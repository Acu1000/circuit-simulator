#pragma once

#include<global.hpp>

class Node;
class Component;

class Terminal {
    private:
    NullableRef<Node> node;
    Component& owner;
    int id;

    public:
    Terminal(Component& p_owner, int p_id);

    int get_id();
    Component& get_owner();
    bool has_node();
    Node& get_node();
    void set_node(Node& p_node);
    void connect(Terminal& other);
};