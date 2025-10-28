#include<simulation/simulation_builder.hpp>

SimulationBuilder* SimulationBuilder::instance = nullptr;

Node& SimulationBuilder::create_node()
{
    Node new_node(nodes.size());
    nodes.push_back(new_node);
    return nodes.back();
}

StaticSimulation SimulationBuilder::build_static()
{
    const int N = nodes.size();
    const int M = voltage_sources.size();

    cout << "Node count: " << N << endl;
    cout << "Source count: " << M << endl;

    StaticSimulation sim(N, M);
    
    // Build Conductance Matrix
    for (int node_id=0; node_id<N; node_id++) {
        Node& node = nodes.at(node_id);
        for (Terminal* t : node.get_terminals()) {
            Component& comp = t->get_owner();
            for (Terminal* ot : comp.get_terminals()) {
                if (t == ot) continue;
                real_t cond = comp.get_conductance(t->get_id(), ot->get_id());

                if (ot->has_node()) {
                    Node& other_node = ot->get_node();
                    sim.add_conductance(node_id, other_node.get_id(), -cond);
                }
                
                sim.add_conductance(node_id, node_id, cond);
            }
        }
    }
    
    // Build connection matrix & voltage source vector
    for (int source_id=0; source_id<M; source_id++) {
        VoltageSource& source = voltage_sources.at(source_id);

        if (source.Plus.has_node()) {
            sim.set_connection(source.Plus.get_node().get_id(), source_id, +1);
        }
        if (source.Minus.has_node()) {
            sim.set_connection(source.Minus.get_node().get_id(), source_id, -1);
        }

        sim.set_voltage_source(source_id, source.get_voltage());
    }

    return sim;
}

void SimulationBuilder::register_voltage_source(VoltageSource& p_source)
{
    voltage_sources.push_back(p_source);
}