#include<iostream>
#include<global.hpp>

#include<simulation/simulation_builder.hpp>
#include<comps/resistor.hpp>

int main() {
    
    Resistor r1(10);
    Resistor r2(20);

    r1.A.connect(r2.B);

    cout << r1.get_conductance() << '\n';
}
