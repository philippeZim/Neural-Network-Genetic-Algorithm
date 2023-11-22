#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int num_of_inputs, int num_of_hidden_layers, int size_of_a_hidden_layer, int num_of_outputs) {
  this->num_of_inputs = num_of_inputs;
  this->num_of_hidden_layers = num_of_hidden_layers;
  this->size_of_a_hidden_layer = size_of_a_hidden_layer;
  this->num_of_outputs = num_of_outputs;
  this->input_layer = Layer(num_of_inputs, num_of_inputs);
  for (int i = 0; i < num_of_hidden_layers; i++) {
      if (i == 0) {
          Layer el = Layer(size_of_a_hidden_layer, num_of_inputs);
          this->hidden_layers.push_back(el);
      } else {
          Layer el = Layer(size_of_a_hidden_layer, size_of_a_hidden_layer);
          this->hidden_layers.push_back(el);
      }
  }
  this->output_layer = Layer(num_of_outputs, size_of_a_hidden_layer);




vector<double> NeuralNetwork::forward(vector<double>& inputs) {
vector<double> input_layer_res = this->input_layer.forward(inputs);
vector<double> cur_res;
for (int i = 0; i < this->hidden_layers.size(); i++) {
    if (i == 0) {
        cur_res = this->hidden_layers[i].forward(input_layer_res);
    } else {
        cur_res = this->hidden_layers[i].forward(cur_res);
    }
}
return this->output_layer.forward(cur_res);


double NeuralNetwork::abs_diff_double(double a, double b) {
double res = a - b;
if (res < 0) {
    return -res;
}
return res;


double NeuralNetwork::squared_error(vector<vector<double>>& inputs, vector<vector<double>>& outputs) {
double res;
for (int i = 0; i < inputs.size(); i++) {
    vector<double> cur_res = this->forward(inputs[i]);
    for (int j = 0; j < cur_res.size(); j++) {
        res += abs_diff_double(cur_res[j], outputs[i][j]);
    }
}
return res * res;

