#include<comps/resistor.hpp>

real_t Resistor::get_conductance(int, int)
{
    return 1.0 / resistance;
}