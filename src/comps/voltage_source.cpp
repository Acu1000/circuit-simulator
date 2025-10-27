#include<comps/voltage_source.hpp>

#include<simulation/simulation_builder.hpp>

VoltageSource::VoltageSource() : Component(2)
{
    SimulationBuilder::get()->register_voltage_source(*this);
}