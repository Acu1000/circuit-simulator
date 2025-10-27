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
    StaticSimulation sim(nodes.size(), voltageSources.size());

    return sim;
}

void SimulationBuilder::register_voltage_source(VoltageSource& p_source)
{
    voltageSources.push_back(p_source);
}