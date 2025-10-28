#include<simulation/static_simulation.hpp>

StaticSimulation::StaticSimulation(int p_node_count, int p_voltage_source_count) :
    node_count(p_node_count),
    voltage_source_count(p_voltage_source_count),
    GBCD(MatrixX::Zero(p_node_count+p_voltage_source_count, p_node_count+p_voltage_source_count)),
    IE(VectorX::Zero(p_node_count+p_voltage_source_count))
{

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

void StaticSimulation::set_voltage_source(int p_source_id, real_t p_voltage)
{
    IE(node_count + p_source_id) = p_voltage;
}

void StaticSimulation::simulate()
{
    //cout << GBCD << '\n';
    //cout << IE << '\n';
    VectorX x = GBCD.colPivHouseholderQr().solve(IE);
    for (int i=0; i<node_count; i++) {
        cout << "Node " << i << " voltage: " << x[i] << "V\n";
    }
    for (int i=0; i<voltage_source_count; i++) {
        cout << "Source " << i+node_count << " current: " << x[i+node_count] << "A\n";
    }
}
