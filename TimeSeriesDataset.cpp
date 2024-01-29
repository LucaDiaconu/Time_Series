//
// Created by lucad on 09/01/2024.
//

#include <valarray>
#include <stdexcept>
#include <iostream>
#include "TimeSeriesDataset.h"
#include "TimeSeriesGenerator.h"

TimeSeriesDataset::TimeSeriesDataset(bool _zNormalise, bool _isTrain):
zNormalize(_zNormalise),isTrain(_isTrain)
{

}

void TimeSeriesDataset::addTimeSeries(vector<double> series, int label) {

    if (zNormalize) {
        normalizeSeries(series);
    }

    data.push_back(series);
    labels.push_back(label);

    if (series.size() > maxLength) {
        maxLength = series.size();
    }

    numberOfSamples++;

}



void TimeSeriesDataset::normalizeSeries(vector<double> series) {
    if (series.empty()){
        return;
    }

    double mean = 0.0;
    for (double value : series){
        mean += value;
    }

    double variance = 0.0;
    for (double value : series){
        variance = pow(value-mean, 2);
    }

    double stanDev = sqrt(variance/series.size());

    for(double& value : series){
        value =(value - mean)/ stanDev;
    }
}

int TimeSeriesDataset::getSize() {
    return maxLength;
}

vector<double> TimeSeriesDataset::TimeSeriesDataset::getTimeSeries(int index) {
        return reinterpret_cast<const vector<double> &>(data[index]);

}

int TimeSeriesDataset::getLabel(int index) const {
    return labels[index];
}




