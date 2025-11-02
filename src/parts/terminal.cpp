#include<parts/terminal.hpp>
#include<simulation/simulation_builder.hpp>

Terminal::Terminal(Component& p_owner, int p_id) : owner(p_owner), id(p_id)
{
}

int Terminal::get_id() {return id;}

Component& Terminal::get_owner()
{
    return owner;   
}

bool Terminal::has_node() 
{
    return node.has_value();
}

Node& Terminal::get_node()
{
    return node->get();
}

int Terminal::get_node_id()
{
    return get_node().get_id();
}

void Terminal::set_node(Node &p_node)
{
    node = p_node;
}

void Terminal::connect(Terminal& other)
{
    if (has_node() && other.has_node()) {
        // TODO: implement node merging
        cerr << "NOT IMPLEMENTED: both terminals already have nodes\n";
        exit(1);
    }
    else if (has_node()) {
        other.set_node(get_node());
        get_node().add_terminal(other);
    }
    else if (other.has_node()) {
        Node& other_node = other.get_node();
        set_node(other_node);
        other_node.add_terminal(*this);
    }
    else {
        Node& new_node = SimulationBuilder::get()->create_node();
        set_node(new_node);
        other.set_node(new_node);
        new_node.add_terminal(*this);
        new_node.add_terminal(other);
    }
}
