//
//  Sorting.hpp
//  Sorting
//
//  Created by Charles Lambert on 11/29/18.
//  Copyright © 2018 Charles Lambert. All rights reserved.
//

#ifndef Sorting_hpp
#define Sorting_hpp
#include "wordInfo.hpp"
#include <string>
#include <stdio.h>

using namespace std;

class Sorting {
    friend class AC;
    void insertionSort(wordInfo *arr[], int len);
    void selectionSort(wordInfo *arr[], int len);
    void quickSort(wordInfo *arr[], int beg, int end);
    int partition(wordInfo *arr[], int beg, int end);
    void mergeSort(wordInfo *arr[], int l1, int l2);
    void merge(wordInfo *arr[], int l, int m, int r);
};
    
#endif /* Sorting_hpp */
