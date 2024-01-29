//
// Created by lucad on 09/01/2024.
//

#include <valarray>
#include <iostream>
#include "SinWaveGenerator.h"


SinWaveGenerator::SinWaveGenerator():
TimeSeriesGenerator(), amplitude(3), frequency(0.5), phase(0.5)
{
}

SinWaveGenerator::SinWaveGenerator(int seed, double _amplitude, double _frequency, double _phase):
TimeSeriesGenerator(seed), amplitude(_amplitude), frequency(_frequency), phase(_phase)
{
}


vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> generatedSeries;
    generatedSeries.reserve(size);

    for(int i = 0 ; i < size ; ++i){
        generatedSeries.push_back(sinusFunction(static_cast<double>(i)));
    }

    return generatedSeries;
}

double SinWaveGenerator::sinusFunction(double i) {
    return amplitude * sin(frequency * i + phase) ;
}

