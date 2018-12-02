//
//  NodeT.hpp
//  Sorting
//
//  Created by Charles Lambert on 11/29/18.
//  Copyright © 2018 Charles Lambert. All rights reserved.
//

#ifndef NODET_HPP_
#define NODET_HPP_
#include "wordInfo.hpp"
#include <string>
using namespace std;
class NodeT {
    friend class AC;
    friend class BSTY;
    wordInfo *w;
    int height;
    NodeT *left;
    NodeT *right;
    NodeT *parent;
public:
    NodeT(string x);
    ~NodeT();
    void printNode();
};
#endif /* NODET_HPP_ */
