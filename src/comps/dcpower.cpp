#include<comps/dcpower.hpp>

DCPower::DCPower(real_t p_voltage) : VoltageSource(), voltage(p_voltage) {}

real_t DCPower::get_voltage()
{
    return voltage;
}