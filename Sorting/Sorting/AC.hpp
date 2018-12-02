//
//  AC.hpp
//  Sorting
//
//  Created by Charles Lambert on 11/29/18.
//  Copyright © 2018 Charles Lambert. All rights reserved.
//

#ifndef AC_HPP_
#define AC_HPP_
#include "wordInfo.hpp"
#include "BSTY.hpp"
#include "Sorting.hpp" // You write
#include <iostream>
using namespace std;
class AC {
    bool verbose;
    BSTY *tree;
    string fn;
    wordInfo **wordarr;
    wordInfo **predictions;
    int currSize;
    string curr;
    Sorting sorts;
public:
    AC(string f1,bool isverbose=false);
    void readFile();
    void convertToArray();
    void convertToArray(NodeT *n);
    void printArr();
    string stripSpace(string s);
    void ui();
    void getPredictions();
    int findBeg();
    int findEnd();
};
#endif /* AC_HPP_ */
