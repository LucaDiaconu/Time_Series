//
// Created by lucad on 09/01/2024.
//

#ifndef KNN_V2_STEPGENERATOR_H
#define KNN_V2_STEPGENERATOR_H

#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    vector<double> generateTimeSeries(int) override;
private:
    double instantValue;

};


#endif //KNN_V2_STEPGENERATOR_H
