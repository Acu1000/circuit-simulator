#include<simulation/simulation_builder.hpp>

SimulationBuilder* SimulationBuilder::instance = nullptr;

Node& SimulationBuilder::create_node()
{
    Node new_node(++node_count);
    nodes.push_back(new_node);
    return nodes.back();
}