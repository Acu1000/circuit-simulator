#include<iostream>
#include<global.hpp>

#include<simulation/simulation_builder.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>

int main() {
    
    Resistor r1(10);
    Resistor r2(10);
    DCPower v1(10);

    v1.Plus.connect(r1.A);
    r1.B.connect(r2.A);

    SimulationBuilder::get()->build_static();
}
