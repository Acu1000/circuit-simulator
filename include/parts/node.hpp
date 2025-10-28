#pragma once

#include<global.hpp>
#include<vector>
#include<unordered_set>

class Terminal;

class Node {
    private:
    unordered_set<Terminal*> terminals;
    int id;

    public:
    Node(int p_id) : id(p_id) {}

    int get_id() {return id;}
    unordered_set<Terminal*> get_terminals();
    void add_terminal(Terminal& p_terminal);
    bool has_terminal(Terminal& p_terminal);
    void remove_terminal(Terminal& p_terminal);
};