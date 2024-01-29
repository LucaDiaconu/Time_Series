//
// Created by lucad on 09/01/2024.
//

#include <cstdlib>
#include "StepGenerator.h"

StepGenerator::StepGenerator():
instantValue(0)
{
}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> generatedSeries;
    generatedSeries.reserve(size); //sert a allouer deja de la mémoire vu que l'on connait déjà sa taille

    for (int i = 0 ; i < size ; ++i){
        double randomProbability = static_cast<double>(rand()) / RAND_MAX;
        if (randomProbability < 0.5){
            instantValue = rand() % 101;
        }

        generatedSeries.push_back(instantValue);
    }

    return generatedSeries;
}


