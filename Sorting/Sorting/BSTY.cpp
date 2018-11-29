#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the 
// binary search tree
// This method should return true if a new node is inserted and 
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!! 
// Note2: after you've inserted a new node, you should call the 
// adjustHeights method that will update the heights of all the 
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x) {
    NodeT *n = new NodeT(x);
    NodeT *tmp = root;
    
    if (root == NULL){
        root = n;
        return true;
    }
    while (tmp->height >= 1){
        if (n->data > tmp->data){
            if (tmp->right != NULL){
                tmp = tmp->right;
            }
            else{
                tmp->right = n;
                n->parent = tmp;
                adjustHeights(tmp);
                return true;
            }
        }
        else if (n->data < tmp->data){
            if (tmp->left != NULL){
                tmp = tmp->left;
            }
            else{
                tmp->left = n;
                n->parent = tmp;
                adjustHeights(tmp);
                return true;
            }
        }
        else {
            cout << "That value is already in the tree!" << endl;
            return false;
        }
    }
    return false;
}

bool BSTY:: insertit(string data, string def) {
    NodeT *n = new NodeT(data, def);
    NodeT *tmp = root;
    
    if (root == NULL){
        root = n;
        return true;
    }
    while (tmp->height >= 1){
        if (n->data > tmp->data){
            if (tmp->right != NULL){
                tmp = tmp->right;
            }
            else{
                tmp->right = n;
                n->parent = tmp;
                adjustHeights(tmp);
                return true;
            }
        }
        else if (n->data < tmp->data){
            if (tmp->left != NULL){
                tmp = tmp->left;
            }
            else{
                tmp->left = n;
                n->parent = tmp;
                adjustHeights(tmp);
                return true;
            }
        }
        else {
            cout << "That value is already in the tree!" << endl;
            return false;
        }
    }
    return false;
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have 
// this working now.  It should be called whenever you change the height of a 
// a particular node.  So, for instance, when a new node is inserted as a leaf, 
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of 
// the height of the left child and the height of the right child, plus 1).  If 
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either 
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.  
void BSTY::adjustHeights(NodeT *n) {
    int balance;
    int balanceLeft;
    int balanceRight;
    
    if (n == NULL){
        return;
    }
    
    while (n->parent != NULL){
        if (n == root){
            return;
        }
        
        if (n->right == NULL && n->left == NULL){
            n->height = 1;
        }
        else if (n->right == NULL){
            n->height = n->left->height + 1;
        }
        else if (n->left == NULL){
            n->height = n->right->height + 1;
        }
        else{
            n->height = max(n->right->height + 1, n->left->height + 1);
        }
        
        balance = findBalance(n);
        balanceLeft = findBalance(n->left);
        balanceRight = findBalance(n->right);
        
        if (balance >= 2){
            if(balanceLeft == -1){
                rotateLeft(n->left);
                rotateRight(n);
            }
            else{
                rotateRight(n);
            }
            adjustHeights(n);
            //adjustHeights(n->parent);
            //balance = findBalance(n);
        }
        if(balance <= -2){
            if (balanceRight == 1){
                rotateRight(n->right);
                rotateLeft(n);
            }
            else{
                rotateLeft(n);
            }
            adjustHeights(n);
            //adjustHeights(n->parent);
            //balance = findBalance(n);
        }
        
         n = n->parent;
    }
    if (n->right == NULL && n->left == NULL){
        root->height = 1;
    }
    else if (n->right == NULL && n->left != NULL){
        root->height = n->left->height + 1;
    }
    else if (n->left == NULL && n->right != NULL){
        root->height = n->right->height + 1;
    }
    else{
        root->height = max(n->right->height + 1, n->left->height + 1);
    }
    
    balance = findBalance(root);
    balanceLeft = findBalance(root->left);
    balanceRight = findBalance(root->right);
    
    if (balance >= 2){
        if(balanceLeft == -1){
            rotateLeft(root->left);
            rotateRight(root);
        }
        else{
            rotateRight(root);
        }
        adjustHeights(n);
        //adjustHeights(n->parent);
        //balance = findBalance(n);
    }
    if(balance <= -2){
        if (balanceRight == 1){
            rotateRight(root->right);
            rotateLeft(root);
        }
        else{
            rotateLeft(root);
        }
        adjustHeights(n);
        //adjustHeights(n->parent);
        //balance = findBalance(n);
    }
    
}

void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
    if (n == NULL){
        return;
    }
    else{
        printTreeIO(n->left);
        n->printNode();
        printTreeIO(n->right);
    }
}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
    if (n == NULL){
        return;
    }
    else{
        n->printNode();
        printTreePre(n->left);
        printTreePre(n->right);
    }
}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
    if (n == NULL){
        return;
    }
    else{
        printTreePost(n->left);
        printTreePost(n->right);
        n->printNode();
    }
}
void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.  
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.  
NodeT *BSTY::find(string x) {
    NodeT *n = root;
    int compCount = 0;
    
    if (n->data == x){ //Covers the root node being picked
        n->printNode();
        return n;
    }
    
    while (n->data != x){
        if (n->height == 1){ //Covers reaching the end
            cout << x << " can't be found" << endl;
            return NULL;
        }
        if (x > n->data){ //Move right
            if (n->right != NULL){
                n = n->right;
                compCount++;
            }
            else{
                cout << x << " can't be found" << endl;
                return NULL;
            }
        }
        else if (x < n->data){ //Move left
            if (n->left != NULL){
                n = n->left;
                compCount++;
            }
            else{
                cout << x << " can't be found" << endl;
                return NULL;
            }
        }
    }
    n->printNode();
    return n;
}

/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.  
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's 
/* right child replaces the node.  
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after 
/* the replacing node is removed from its old location but before it is inserted into its 
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes teh node, and returns 
/* true if the removal was successful.
*/
bool BSTY::remove(string s) {
    NodeT *tmp = root;
    while (tmp->height >= 1){
        if (tmp->data == s){
            if (tmp->height == 1){
                remove1(tmp);
                return true;
            }
            else if(tmp->height == 2){
                remove2(tmp);
                return true;
            }
            else if(tmp->height == 3){
                remove3(tmp);
                return true;
            }
            else{
                remove2(tmp);
                return true;
            }
        }
        else{
            if(tmp->right != NULL){
                if(s > tmp->data){
                    tmp = tmp->right;
                }
            }
            if(tmp->left != NULL){
                if (s < tmp->data){
                    tmp = tmp->left;
                }
            }
    
    }
    }
    return false;
}

/* remove1(): called when the node to be removed has no children. Takes as input the 
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
*/
void BSTY::remove1(NodeT *n) {
    n->printNode();
    if (n == root){
        if (n->right != NULL){
            n = n->right;
            root = n;
            return;
        }
        else {
            n = n->left;
            root = n;
            return;
        }
    }
    
    if (n->parent->left == n){
        n->parent->left = NULL;
    }
    else{
        n->parent->right = NULL;
    }
    
    while (n->parent->parent != NULL){
        n->parent->height--;
        n->parent = n->parent->parent;
    }
}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.  
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the 
/* one child becomes the root.
*/ 
void BSTY::remove2(NodeT *n) {
    n->printNode();
    if(n == root){
        if (n->right != NULL){
            n = n->right;
            root = n;
            return;
        }
        else {
            n = n->left;
            root = n;
            return;
        }
    }
    
    if(n->parent->left == n){
        n->parent->left = n->left;
        n->left->parent = n->left->parent->parent;
    }
    else{
        n->parent->right = n->right;
        n->right->parent = n->right->parent->parent;
    }
    
    while(n->parent != NULL){
        n->parent->height--;
        n->parent = n->parent->parent;
    }
}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the 
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or 
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the 
/* removed node's left child (and the child must point to the new node as a parent), 
/* and the same for teh right child.
/* Remember to take into account that the node being removed might be the root.
*/
void BSTY::remove3(NodeT *n) {
    cout << "Remove 3 Called" << endl;
}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
/* right child.  The left-most descendent is returned.
*/
NodeT *BSTY::findMin(NodeT *n) {
    while (n->left != NULL){
        n = n->left;
    }
    return n;
}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}

NodeT *BSTY::rotateRight(NodeT *n){
    cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;
    
    if (n == root){
        NodeT *tmp = n->left;
        NodeT *tmp2 = tmp->right;
        tmp->right = n;
        n->left = tmp2;
        tmp->parent = n->parent;
        n->parent = tmp;
        root = tmp;
        
        //adjustHeights(n);
        
        return tmp;
    }
    
    if (n->right == NULL || n->left == NULL){
        NodeT *tmp = n->left;
        NodeT *tmp2 = tmp->right;
        tmp->right = n;
        n->left = tmp2;
        tmp->parent = n->parent;
        tmp->parent->left = tmp;
        n->parent = tmp;
        //n->left = NULL;
        if(n == root){
            root = tmp;
        }
        //adjustHeights(n);
        
        return tmp;
    }
    
    NodeT *tmp = n->left;
    NodeT *tmp2 = tmp->right;
    n->parent->left = tmp;
    tmp->right = n;
    n->left = tmp2;
    tmp->parent = n->parent;
    n->parent = tmp;
    if (tmp2 != NULL){
        tmp2->parent = n;
    }
    //adjustHeights(n);
    
    
    return tmp;
}

NodeT *BSTY::rotateLeft(NodeT *n){
    cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;
    
    if (n == root){
        NodeT *tmp = n->right;
        NodeT *tmp2 = tmp->left;
        tmp->left = n;
        n->right = tmp2;
        tmp->parent = n->parent;
        n->parent = tmp;
        root = tmp;
        
        //adjustHeights(n);
        
        return tmp;
    }
    
    if (n->right == NULL || n->left == NULL){
        NodeT *tmp = n->right;
        NodeT *tmp2 = tmp->left;
        tmp->left = n;
        n->right = tmp2;
        tmp->parent = n->parent;
        tmp->parent->right = tmp;
        n->parent = tmp;
        if(n == root){
            root = tmp;
        }
        //adjustHeights(n);
        
        return tmp;
    }
    
    NodeT *tmp = n->right;
    NodeT *tmp2 = tmp->left;
    n->parent->right = tmp;
    tmp->left = n;
    n->right = tmp2;
    tmp->parent = n->parent;
    n->parent = tmp;
    if (tmp2 != NULL){
        tmp2->parent = n;
    }
    //adjustHeights(n);
    
    return tmp;
}

int BSTY::findBalance(NodeT *n){
    int balance = 0;
    
    if (n == NULL){
        return balance;
    }
    
    if (n->right != NULL && n->left != NULL){
        balance = n->left->height - n->right->height;
    }
    else if (n->right == NULL && n->left == NULL){
        balance = 0;
    }
    else if (n->right == NULL){
        balance = n->left->height;
    }
    else if (n->left == NULL){
        balance = -(n->right->height);
    }
    
    return balance;
}



/************************************************************************/

