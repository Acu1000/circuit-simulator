#pragma once

#include<global.hpp>
#include<comps/component.hpp>

// Abstract
class VoltageSource : protected Component {
    public:
    Terminal& Plus = terminals[0];
    Terminal& Minus = terminals[1];

    VoltageSource();

    virtual real_t get_voltage() = 0;
};