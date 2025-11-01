#pragma once

#include<global.hpp>
#include<parts/terminal.hpp>
#include<array>

class Simulation;

class Component {
    protected:
    int terminal_count;
    vector<Terminal> terminals;

    Component(int p_terminal_count=2);

    public:
    virtual real_t get_conductance(int, int) {return 0;}
    vector<Terminal*> get_terminals();
    virtual void build(Simulation& sim) {};
};