#pragma once

#include<global.hpp>
#include<Eigen/Dense>

typedef Eigen::Matrix<real_t, Eigen::Dynamic, Eigen::Dynamic> MatrixX;
typedef Eigen::Vector<real_t, Eigen::Dynamic> VectorX;
typedef Eigen::Block<real_t, Eigen::Dynamic, Eigen::Dynamic> BlockX;

class Simulation {

    private:
    int node_count;
    int voltage_source_count;
    
    // Conductance matrix
    MatrixX G;
    // Connection matrices
    MatrixX B, C; 
    // Dependent source matrix
    MatrixX D;
    // Injected current vector
    VectorX I;
    // Source voltage vector
    VectorX E;

    public:
    Simulation(int p_node_count);
    void add_base_conductance(int p_node_id1, int p_node_id2, real_t p_conductance);

    // Registers a new voltage source in the simulation and returns its id
    int add_voltage_source();
    void set_connection(int p_node_id, int p_source_id, int p_value);
    void set_source_voltage(int p_source_id, real_t p_voltage);
    void simulate();
};