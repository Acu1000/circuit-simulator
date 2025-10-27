#pragma once

#include<global.hpp>
#include<comps/voltage_source.hpp>

class DCPower : public VoltageSource {
    private:
    real_t voltage;

    public:
    DCPower(real_t p_voltage);
    real_t get_voltage() override;
};