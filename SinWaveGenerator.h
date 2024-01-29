//
// Created by lucad on 09/01/2024.
//

#ifndef KNN_V2_SINWAVEGENERATOR_H
#define KNN_V2_SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator{
public:
    SinWaveGenerator();
    SinWaveGenerator(int,double,double,double);
    vector<double> generateTimeSeries(int) override;
    double sinusFunction(double);
private:
    double amplitude;
    double frequency;
    double phase;
};


#endif //KNN_V2_SINWAVEGENERATOR_H
