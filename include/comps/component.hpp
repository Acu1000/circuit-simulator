#pragma once

#include<global.hpp>
#include<parts/terminal.hpp>

// Abstract
template<int TERMINAL_COUNT>
class Component {
    protected:
    Terminal terminals[TERMINAL_COUNT];

    Component() {
        for (int i=0; i<TERMINAL_COUNT; i++) {
            terminals[i].set_id(i);
        }
    }

    public:
    virtual real_t get_conductance(int, int) {return 0;}
};