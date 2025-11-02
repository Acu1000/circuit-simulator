#pragma once

#include<global.hpp>
#include<vector>
#include<parts/node.hpp>
#include<comps/voltage_source.hpp>

// Singleton
class SimulationBuilder {
    protected:
    static SimulationBuilder* instance;
    SimulationBuilder() {}

    public:
    static SimulationBuilder* get() {
        if (instance == nullptr) {
            instance = new SimulationBuilder();
        }
        return instance;
    }

    // prevent cloning and assigning
    SimulationBuilder(SimulationBuilder& other) = delete;
    void operator=(const SimulationBuilder &) = delete;

    private:
    vector<Node> nodes;
    RefVector<Component> components;

    public:
    Node& create_node();
    Simulation build();
    void add_component(Component& p_component);

};