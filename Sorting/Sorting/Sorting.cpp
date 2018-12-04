//
//  Sorting.cpp
//  Sorting
//
//  Created by Charles Lambert on 11/29/18.
//  Copyright © 2018 Charles Lambert. All rights reserved.
//

#include "Sorting.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

void Sorting::insertionSort(wordInfo *arr[], int len){
    wordInfo nArr[len];
    nArr[0] = *arr[0];
    for (int i = 0; i < len; i++){
        int j = i - 1;
        while (j >= 0 && nArr[j].ct > arr[i]->ct){
            nArr[j+1] = nArr[j];
            j = j - 1;
        }
        nArr[j+1] = *arr[i];
    }
    *arr = nArr;
}

void Sorting::selectionSort(wordInfo *arr[], int len){
    for (int i = 0; i < len; i++){
        for (int j = i+1; j < len; j++){
            if (arr[i]->ct < arr[j]->ct){
                wordInfo tmp = *arr[j];
                arr[j-1] = arr[i];
                arr[i] = arr[j];
            }
        }
    }
}

void Sorting::quickSort(wordInfo *arr[], int beg, int end){
    
}

void Sorting::mergeSort(wordInfo *arr[], int l1, int l2){
    
}

void Sorting::merge(wordInfo *arr[], int l, int m, int r){
    
}
