#include<simulation/static_simulation.hpp>

StaticSimulation::StaticSimulation(int p_node_count, int p_voltage_source_count) :
    node_count(p_node_count),
    voltage_source_count(p_voltage_source_count),
    GBCD(MatrixX::Zero(p_node_count+p_voltage_source_count, p_node_count+p_voltage_source_count))
{
    cout << GBCD << '\n';
}

void StaticSimulation::add_conductance(int p_node_id1, int p_node_id2, real_t p_conductance)
{
    GBCD(p_node_id1, p_node_id2) += p_conductance;
}

void StaticSimulation::set_connection(int p_node_id, int p_source_id, int p_value)
{
    GBCD.block(0, node_count, node_count, voltage_source_count)(p_node_id, p_source_id) = p_value;
    GBCD.block(node_count, 0, voltage_source_count, node_count)(p_node_id, p_source_id) = p_value;
}
