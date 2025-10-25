#pragma once

#include<global.hpp>
#include<vector>
#include<parts/node.hpp>

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
    int node_count = 0;

    public:
    Node& create_node();

};