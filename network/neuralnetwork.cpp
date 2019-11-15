#include "neuralnetwork.h"
#include <cmath>
#include <random>

neuralnetwork::neuralnetwork(int grid_diameter,
                             int kernel_radius,
                             int hidden_neurons,
                             int mutation_rate,
                             int number_of_kernels):
    grid_size_(pow(grid_diameter, 2)),
    number_of_kernels_(number_of_kernels),
    kernel_radius_(kernel_radius),
    kernel_side_(2*kernel_radius + 1),
    hidden_layer_size_(hidden_neurons),
    mutation_rate_(mutation_rate)

{
    //initialize weights to zero
    for (int i = 0; i < number_of_kernels; i++){
        vector<float> kernel(0, pow(kernel_side_, 2));
        kernels_.push_back(kernel);
    }
    for (int neuron = 0; neuron < hidden_neurons; neuron++){
        vector<float> convoluted_inputs(0, pow(grid_diameter - 2*kernel_radius, 2)*number_of_kernels);
        hidden_layer_.push_back(convoluted_inputs);
    }
    for (int output = 0; output < pow(grid_diameter,2); output++){
        vector<float> hidden_layer_output(0, hidden_neurons);
        output_.push_back(hidden_layer_output);
    }
}

void neuralnetwork::randomize(){
    vector<vector<float>>::iterator it1;
    vector<float>::iterator it2;
    for (it1 = kernels_.begin(); it1 < kernels_.end(); it1++){
        for (it2 = it1->begin(); it2 < it1->end(); it2++){
            *it2 = random_weight();
        }
    }
    for (it1 = hidden_layer_.begin(); it1 < hidden_layer_.end(); it1++){
        for (it2 = it1->begin(); it2 < it1->end(); it2++){
            *it2 = random_weight();
        }
    }
    for (it1 = output_.begin(); it1 < output_.end(); it1++){
        for (it2 = it1->begin(); it2 < it1->end(); it2++){
            *it2 = random_weight();
        }
    }
}

float neuralnetwork::random_weight(){
    return rand() % 10000 / 5000 - 1;
}
