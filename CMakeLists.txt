cmake_minimum_required(VERSION 3.26)
project(KNN_V2)

set(CMAKE_CXX_STANDARD 17)

add_executable(KNN_V2 main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h
        StepGenerator.cpp
        StepGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.h
        TimeSeriesDataset.cpp
        TimeSeriesDataset.h
        KNN.cpp
        KNN.h)
