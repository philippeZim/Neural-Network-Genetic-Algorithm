#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include <vector>
#include <random>

class Layer {
    private:
        int num_of_inputs;
        int num_of_neurons;
        std::vector<double> neurons;
        std::vector<std::vector<double>> weights;
    public:
        double randomBetweenZeroAndOne();
        Layer(int num_of_neurons, int num_of_inputs);
        std::vector<double> forward(std::vector<double>& inputs);
};

#endif