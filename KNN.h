//
// Created by lucad on 10/01/2024.
//

#ifndef KNN_V2_KNN_H
#define KNN_V2_KNN_H

#import <string>
#include <vector>
#import "TimeSeriesDataset.h"


using namespace std;

class KNN {
public:

    KNN(int , const string&);

    double evaluate(TimeSeriesDataset, TimeSeriesDataset, const vector <int>&) ;

protected:
    int k;
    string similarity_measure;

    double euclideanDistance(const vector<double> &series1, const vector<double> &series2);

    double dtwDistance(const vector<double> &series1, const vector<double> &series2);
};


#endif //KNN_V2_KNN_H
