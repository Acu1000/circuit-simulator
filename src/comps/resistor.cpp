#include<comps/resistor.hpp>

Resistor::Resistor(real_t p_resistance) : Component<2>(), resistance(p_resistance)  {
    
}

real_t Resistor::get_conductance(int, int)
{
    return 1.0 / resistance;
}