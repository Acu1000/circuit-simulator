#include<parts/terminal.hpp>
#include<simulation/simulation_builder.hpp>

Terminal::Terminal(Component& p_owner, int p_id) : owner(p_owner), id(p_id)
{
}

int Terminal::get_id() {return id;}

bool Terminal::has_node() 
{
    return node.has_value();
}

Node& Terminal::get_node()
{
    return node->get();
}

void Terminal::set_node(Node& p_node)
{
    node = p_node;
}

void Terminal::disconnect()
{
    node.reset();
}

void Terminal::connect(Terminal& other)
{
    if (other.has_node()) {
        set_node(other.get_node());
    }
    else {
        Node& new_node = SimulationBuilder::get()->create_node();
        set_node(new_node);
        other.set_node(new_node);
    }
}
