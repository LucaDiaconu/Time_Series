//
// Created by lucad on 09/01/2024.
//

#include <iostream>
#include "TimeSeriesGenerator.h"

TimeSeriesGenerator::TimeSeriesGenerator():
seed(0)
{
}
TimeSeriesGenerator::TimeSeriesGenerator(int _seed):
        seed(_seed)
{
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> _series) {
    cout << "Time Series: ";
    for (const auto& value : _series) {
        cout << value << " ";
    }
    cout << endl;
}
