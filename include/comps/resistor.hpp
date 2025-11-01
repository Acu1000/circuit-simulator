#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class Resistor : Component {
    public:
    Terminal& A = terminals[0];
    Terminal& B = terminals[1];

    Resistor(real_t p_resistance);

    real_t get_conductance(int=0, int=0) override;
    void build(Simulation& sim) override;

    private:
    real_t resistance;

};