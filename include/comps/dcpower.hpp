#pragma once

#include<global.hpp>
#include<comps/component.hpp>

class DCPower : public Component {
    private:
    real_t voltage;

    public:
    Terminal& Plus = terminals[0];
    Terminal& Minus = terminals[1];

    DCPower(real_t p_voltage);
    void build(Simulation& sim) override;
};