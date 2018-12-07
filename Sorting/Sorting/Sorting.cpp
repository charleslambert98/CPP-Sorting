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
    if (l1 < l2){
        int m = (l1+l2)/2;
        
        mergeSort(arr, l1, m);
        mergeSort(arr, m+1, l2);
        
        merge(arr, l1, m, l2);
    }
}

void Sorting::merge(wordInfo *arr[], int l, int m, int r){
    int i, j, k;
    
    int len1 = m - 1 + 1;
    int len2 = r - m;
    
    wordInfo *nArr1[len1], *nArr2[len2];
    
    for (i = 0; i < len1; i++){
        nArr1[i] = arr[i+1];
    }
    for (j = 0; j < len2; j++){
        nArr2[j] = arr[m+1+j];
    }
    
    i = 0;
    j = 0;
    k = 1;
    
    while(i < len1 && j < len2){
        if (nArr1[i]->ct > nArr2[j]->ct){
            arr[k] = nArr1[i];
            i++;
        }
        else{
            arr[k] = nArr2[j];
            j++;
        }
        k++;
    }
    while (j < len2){
        arr[k] = nArr2[j];
        j++;
        k++;
    }
}
