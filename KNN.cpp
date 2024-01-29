//
// Created by lucad on 10/01/2024.
//

#include <algorithm>
#include <stdexcept>
#include <valarray>
#include "KNN.h"
#include "TimeSeriesGenerator.h"


KNN::KNN(int _k, const string& similarityMeasure):
k(_k), similarity_measure(similarityMeasure)
{
}


double KNN::euclideanDistance(const vector<double>& series1, const vector<double>& series2) {
    if (series1.size() != series2.size()) {
        // Gérer le cas où les séries n'ont pas la même longueur
        throw invalid_argument("Series lengths do not match");
    }

    // Calcul de la distance euclidienne
    double distance = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        distance += pow(series1[i] - series2[i], 2);
    }

    return sqrt(distance);
}

double KNN::dtwDistance(const vector<double>& series1, const vector<double>& series2) {
    const size_t len1 = series1.size();
    const size_t len2 = series2.size();


    vector<vector<double>> costMatrix(len1 + 1, vector<double>(len2 + 1, 0.0));


    for (size_t i = 0; i <= len1; ++i) {
        costMatrix[i][0] = numeric_limits<double>::infinity();
    }
    for (size_t j = 0; j <= len2; ++j) {
        costMatrix[0][j] = numeric_limits<double>::infinity();
    }
    costMatrix[0][0] = 0.0;


    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            double cost = pow(series1[i - 1] - series2[j - 1], 2);
            cost += min({
                                costMatrix[i][j - 1],  // Insertion
                                costMatrix[i - 1][j],  // Suppression
                                costMatrix[i - 1][j - 1]  // Correspondance
                        });
            costMatrix[i][j] = cost;
        }
    }


    return sqrt(costMatrix[len1][len2]);
}


double KNN::evaluate(TimeSeriesDataset trainData, TimeSeriesDataset testData, const vector<int>& groundtruth) {
    size_t testSize = testData.getSize();
    if (testSize != groundtruth.size()) {
        return 0.0;
    }

    int correctCount = 0;

    // Boucle sur les données de test
    for (size_t i = 0; i < testSize; ++i) {
        vector<pair<double, int>> neighbors;

        // Calcul de la similarité avec les données d'entraînement
        for (size_t j = 0; j < trainData.getSize(); ++j) {
            double similarity = euclideanDistance(testData.getTimeSeries(i), trainData.getTimeSeries(j));
            neighbors.emplace_back(similarity, trainData.getLabel(j));
        }

        // Tri des voisins par similarité croissante
        sort(neighbors.begin(), neighbors.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        // Sélection des k plus proches voisins
        vector<int> kNearestLabels;
        for (int m = 0; m < k; ++m) {
            kNearestLabels.push_back(neighbors[m].second);
        }

        // Comparaison avec les groundtruths
        if (find(kNearestLabels.begin(), kNearestLabels.end(), groundtruth[i]) != kNearestLabels.end()) {
            correctCount++;
        }
    }

    // Calcul de l'exactitude
    double accuracy = static_cast<double>(correctCount) / testSize;
    return accuracy;
}