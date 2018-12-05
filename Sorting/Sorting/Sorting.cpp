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
    if (end - beg > 1){
        int pivot = partition(arr, beg, end);
        quickSort(arr, beg, pivot-1);
        quickSort(arr, beg, pivot+1);
    }
}

int Sorting::partition(wordInfo *arr[], int beg, int end){
    int part = beg;
    int pivot = arr[beg]->ct;
    int i = beg + 1;
    int j = end;
    wordInfo tmp;
    while (i <= j){
        while (arr[i]->ct < pivot){
            i++;
        }
        while (arr[j]->ct > pivot){
            j--;
        }
        if (i <= j){
            tmp = *arr[i];
            arr[i] = arr[j];
            *arr[j] = tmp;
            i++;
            j--;
        }
    }
    return part;
}

void Sorting::mergeSort(wordInfo *arr[], int l1, int l2){
    
}

void Sorting::merge(wordInfo *arr[], int l, int m, int r){
    
}
