#pragma once

#include<global.hpp>

class Node;

class Terminal {
    private:
    NullableRef<Node> node;
    int id;

    public:
    int get_id();
    void set_id(int p_id);
    bool has_node();
    Node& get_node();
    void set_node(Node& p_node);
    void connect(Terminal& other);
    void disconnect();
};