#include<iostream>
#include<global.hpp>

#include<simulation/simulation_builder.hpp>
#include<comps/resistor.hpp>
#include<comps/dcpower.hpp>

int main() {
    
    Resistor r1(10);
    DCPower v1(10);

    v1.Plus.connect(r1.A);

    cout << r1.get_conductance() << '\n';
}
