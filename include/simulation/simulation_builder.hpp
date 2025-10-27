#pragma once

#include<global.hpp>
#include<vector>
#include<parts/node.hpp>
#include<simulation/static_simulation.hpp>
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
    RefVector<VoltageSource> voltageSources;

    public:
    Node& create_node();
    StaticSimulation build_static();
    void register_voltage_source(VoltageSource& p_source);

};