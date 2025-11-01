#include<comps/resistor.hpp>
#include<simulation/simulation.hpp>
#include<parts/node.hpp>

Resistor::Resistor(real_t p_resistance) : Component(2), resistance(p_resistance)  {
    
}

real_t Resistor::get_conductance(int, int)
{
    return 1.0 / resistance;
}

void Resistor::build(Simulation &sim)
{
    if (A.has_node()) {
        int node_a_id = A.get_node_id();
        sim.add_base_conductance(node_a_id, node_a_id, 1.0 / resistance);
    }
    if (B.has_node()) {
        int node_b_id = B.get_node_id();
        sim.add_base_conductance(node_b_id, node_b_id, 1.0 / resistance);
    }
    if (A.has_node() && B.has_node()) {
        int node_a_id = A.get_node_id();
        int node_b_id = B.get_node_id();
        sim.add_base_conductance(node_a_id, node_b_id, -1.0 / resistance);
    }
}