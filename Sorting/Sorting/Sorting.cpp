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
    wordInfo val;
    int j;
    for (int i = 0; i < len; i++){
        val = *arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j]->ct < val.ct){
            *arr[j+1] = *arr[j];
            j = j - 1;
        }
        *arr[j+1] = val;
    }
}

void Sorting::selectionSort(wordInfo *arr[], int len){
    for (int i = 0; i < len; i++){
        for (int j = i+1; j < len - 1; j++){
            if (arr[j]->ct > arr[i]->ct){
                wordInfo tmp = *arr[i];
                *arr[i] = *arr[j];
                *arr[j] = tmp;
            }
        }
    }
}

void Sorting::quickSort(wordInfo *arr[], int beg, int end){
    if (beg < end){
        int pivot = partition(arr, beg, end);
        quickSort(arr, beg, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

int Sorting::partition(wordInfo *arr[], int beg, int end){
    int pivot = arr[end]->ct;
    int i = beg - 1;
    
    for(int j = beg; j < end; j++){
        if (arr[j]->ct > pivot){
            i++;
            wordInfo tmp = *arr[i];
            *arr[i] = *arr[j];
            *arr[j] = tmp;
        }
    }
    wordInfo tmp2 = *arr[i+1];
    *arr[i+1] = *arr[end];
    *arr[end] = tmp2;
    return i+1;
}

void Sorting::mergeSort(wordInfo *arr[], int l1, int l2){
    
}

void Sorting::merge(wordInfo *arr[], int l, int m, int r){
    
}
