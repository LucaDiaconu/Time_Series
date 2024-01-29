//
// Created by lucad on 09/01/2024.
//

#include <cstdlib>
#include <cmath>
#include <valarray>
#include <iostream>
#include "GaussianGenerator.h"
GaussianGenerator::GaussianGenerator()
        : mean(0), stanDev(1) {

}
vector<double> GaussianGenerator::generateTimeSeries(int _size) {

    vector<double> generatedSeries;
    generatedSeries.reserve(_size);

    for (int i = 0; i < generatedSeries.size(); i++){
        double gaussianBoxMuller = generateGaussianBoxMuller();
        generatedSeries.push_back(gaussianBoxMuller);
    }


    return generatedSeries;
}

double GaussianGenerator::generateGaussianBoxMuller() const {

    double u1 = static_cast<double>(rand())/RAND_MAX;
    double u2 = static_cast<double>(rand())/RAND_MAX;
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return z0 * stanDev + mean;
}

GaussianGenerator::GaussianGenerator(double _mean, double _stanDev):
mean(_mean), stanDev(_stanDev)
{

}

