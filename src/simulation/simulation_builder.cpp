#include<simulation/simulation_builder.hpp>
#include<simulation/simulation.hpp>

SimulationBuilder* SimulationBuilder::instance = nullptr;

Node& SimulationBuilder::create_node()
{
    Node new_node(nodes.size());
    nodes.push_back(new_node);
    return nodes.back();
}

void SimulationBuilder::add_component(Component &p_component)
{
    components.push_back(p_component);
}

Simulation SimulationBuilder::build() {
    Simulation sim(nodes.size());

    for (Component& comp : components) {
        comp.build(sim);
    }

    return sim;
}