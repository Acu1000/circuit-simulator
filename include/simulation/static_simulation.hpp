#pragma once

#include<global.hpp>
#include<Eigen/Dense>

typedef Eigen::Matrix<real_t, Eigen::Dynamic, Eigen::Dynamic> MatrixX;
typedef Eigen::Vector<real_t, Eigen::Dynamic> VectorX;
typedef Eigen::Block<real_t, Eigen::Dynamic, Eigen::Dynamic> BlockX;

class StaticSimulation {

    private:
    int node_count;
    int voltage_source_count;

    MatrixX GBCD;
    VectorX IE;

    public:
    StaticSimulation(int p_node_count, int p_voltage_source_count);
    void add_conductance(int p_node_id1, int p_node_id2, real_t p_conductance);
    void set_connection(int p_node_id, int p_source_id, int p_value);
    void set_voltage_source(int p_source_id, real_t p_voltage);
    void simulate();
};