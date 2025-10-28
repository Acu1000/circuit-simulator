#include<iostream>
#include<global.hpp>

#include<simulation/simulation_builder.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>

int main() {
    
    Resistor r1(40);
    Resistor r2(20);
    Resistor r3(40);
    DCPower v1(10);

    // - v1 -- r1 -- r2 -

    v1.Plus.connect(r1.A);
    r1.B.connect(r2.A);
    r1.B.connect(r3.A);

    SimulationBuilder::get()->build_static();
}
