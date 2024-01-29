//
// Created by lucad on 09/01/2024.
//

#ifndef KNN_V2_TIMESERIESDATASET_H
#define KNN_V2_TIMESERIESDATASET_H

#include <vector>

using namespace std;

class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool, bool);
    void addTimeSeries(vector<double>, int);
    void addTimeSeries(vector<double>, int label = 3);
    void normalizeSeries(vector<double>);
    int getSize();
    int getLabel(int) const;
    vector<double> getTimeSeries(int);

private:
    bool zNormalize;
    bool isTrain;
    vector<vector<double>> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};


#endif //KNN_V2_TIMESERIESDATASET_H
