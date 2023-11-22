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
        
        double randomBetweenZeroAndOne() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);
            return dis(gen);
        }

        Layer(int num_of_neurons, int num_of_inputs) {
            this->num_of_inputs = num_of_inputs;
            this->num_of_neurons = num_of_neurons;
            /* 
              init the weights : every neuron is connected to all inputs with a weight
              weight[i][j] -> i would specify the neuron and j the weight coresponding
              to the input
            */
            for (int i = 0; i < num_of_neurons; i++) {
              std::vector<double> el;
              for (int j = 0; j < num_of_inputs; j++) {
                el.push_back(randomBetweenZeroAndOne());
              }
              this->weights.push_back(el);
            }
        }

        std::vector<double> forward(std::vector<double>& inputs) {
            
            std::vector<double> outputs;
            for (int i = 0; i < num_of_neurons; i++) {
                double el = 0.;
                for (int j = 0; j < num_of_inputs; j++) {
                    el += inputs[j] * this->weights[i][j];
                }
                outputs.push_back(el);
            }
            return outputs;
        }
    
};