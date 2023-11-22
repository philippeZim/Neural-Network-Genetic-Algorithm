#include <iostream>
#include <vector>
#include "Layer.h"

int main() {
    Layer l1 = Layer(4, 2);
    std::vector<double> inputs = {0.8, 0.5};
    std::vector<double> outputs = l1.forward(inputs);
    for (int i = 0; i < outputs.size(); i++) {
        std::cout << outputs[i] << "\n";
    }
  
    return 0;
}