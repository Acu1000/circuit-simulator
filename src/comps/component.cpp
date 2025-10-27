#include<comps/component.hpp>

Component::Component(int p_terminal_count) : terminal_count(p_terminal_count)
{
    for (int i=0; i<terminal_count; i++) {
        Terminal new_terminal(*this, i);
        terminals.push_back(new_terminal);
    }
}