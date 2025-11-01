#include<comps/dcpower.hpp>
#include<simulation/simulation.hpp>

DCPower::DCPower(real_t p_voltage) : VoltageSource(), voltage(p_voltage) {}

real_t DCPower::get_voltage()
{
    return voltage;
}

void DCPower::build(Simulation &sim)
{
    if (Plus.has_node() || Minus.has_node()) {
        int id = sim.add_voltage_source();
        sim.set_source_voltage(id, voltage); // TODO: might have to make this dynamic instead

        if (Plus.has_node()) {
            sim.set_connection(Plus.get_node_id(), id, +1);
        }

        if (Minus.has_node()) {
            sim.set_connection(Minus.get_node_id(), id, -1);
        }
    }
}