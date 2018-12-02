//
//  wordInfo.hpp
//  Sorting
//
//  Created by Charles Lambert on 11/29/18.
//  Copyright © 2018 Charles Lambert. All rights reserved.
//

#ifndef WORDINFO_HPP_
#define WORDINFO_HPP_
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class wordInfo {
    friend class NodeT;
    friend class BSTY;
    friend class Sorting;
    friend class AC;
    string word;
    int ct;
public:
    wordInfo(string w, int x);
    wordInfo(string w);
    wordInfo();
    void printWord();
};

#endif /*WORDINFO_HPP_*/
