//
// Created by lucad on 09/01/2024.
//

#ifndef KNN_V2_TIMESERIESGENERATOR_H
#define KNN_V2_TIMESERIESGENERATOR_H

#include <vector>

using namespace std;

class TimeSeriesGenerator {
public:

    TimeSeriesGenerator();
    TimeSeriesGenerator(int);
    virtual vector<double> generateTimeSeries(int) = 0;
    void printTimeSeries(const vector<double>);

private:
    int seed;

};


#endif //KNN_V2_TIMESERIESGENERATOR_H
