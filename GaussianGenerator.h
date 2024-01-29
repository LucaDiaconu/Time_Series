//
// Created by lucad on 09/01/2024.
//

#ifndef KNN_V2_GAUSSIANGENERATOR_H
#define KNN_V2_GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"

class GaussianGenerator : public  TimeSeriesGenerator{
public:
    GaussianGenerator();
    GaussianGenerator(double, double);
    vector<double> generateTimeSeries(int) override;
    double generateGaussianBoxMuller() const;
private:
    double mean;
    double stanDev;

};


#endif //KNN_V2_GAUSSIANGENERATOR_H
