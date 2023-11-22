#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "Layer.h"

class NeuralNetwork {
    private:
        int num_of_inputs;
        int num_of_hidden_layers;
        int size_of_a_hidden_layer;
        int num_of_outputs;
        Layer input_layer;
        vector<Layer> hidden_layers;
        Layer output_layer;
  public:
      NeuralNetwork(int num_of_inputs, int num_of_hidden_layers, int size_of_a_hidden_layer, int num_of_outputs);
    vector<double> forward(vector<double>& inputs);
    double abs_diff_double(double a, double b);
    double squared_error(vector<vector<double>>& inputs, vector<vector<double>>& outputs);
};

#endif