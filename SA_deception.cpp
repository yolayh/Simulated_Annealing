#include "SA_deception.hpp"

int main(int argc, char *argv[]){

    const double temperature = atof(argv[1]);
    const double annealing = atof(argv[2]);
    const int bit = atoi(argv[3]);
    const int run = atoi(argv[4]);
    const int iteration = atoi(argv[5]);
    
    execution(temperature, annealing, bit, run, iteration);

    return 0;

}