//
//  NodeT.cpp
//  Sorting
//
//  Created by Charles Lambert on 11/29/18.
//  Copyright © 2018 Charles Lambert. All rights reserved.
//

#include "NodeT.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
NodeT::NodeT(string x) {
    w = new wordInfo(x);
    left = NULL;
    right = NULL;
    parent = NULL;
    height = 1;
}
NodeT::~NodeT() {
    if ((left != NULL) || (right != NULL)) {
        cout << "deleting may leave dangling Nodes" << endl;
    }
}
void NodeT::printNode() {
    cout << "|"<<w->word << "("<< height <<"): " <<w->ct<<"|" <<endl;
}
