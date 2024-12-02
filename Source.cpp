/*
AVL Tree Assignment, Melody Phillips, December 8 2024
    Description: Takes a text file full of numbers and writes a new text file with a
corresponding tree.
    Includes functions: rotate left, rotate right, rebalance, insert, and print.
    Assumptions: input text file does not need error checking, no deleting necessary
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

//STRUCTURES
struct node 
{
    //functions
    node(int data) {
        key = data;
        left = nullptr;
        right = nullptr;
        height = 0;
    }

    //variables
    node* left;
    node* right;
    int key;
    int height;
};

struct tree 
{
    //functions
    tree(node* newRoot) {
        root = newRoot;
    }
    node* leftRotate(node* x);
    node* rightRotate(node* x);
    node* rebalance(node* node);      //*note: adjusts height
    node* insert(node* node, int data);
    int height(node* node);
    int getBalance(node* node);
    void print(); //reffer to his instructions

    //variables
    node* root;
    //height of tree is height of root node
};




//FUNCTIONS
node* tree::rebalance(node* node) 
{//note* remember to adjust the height of each node on the way up, before and after each call to rebalance?
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);  //node->left - node->right

    /*do rotations as necessary
      If Left heavy outside :  return rightRotate(node);
      If right heavy outside:  return leftRotate(node);
      If left heavy inside:  left rotation first, right rotation 2nd, return top node
            node->left =  leftRotate(node->left);
            return rightRotate(node);
     if right heavy inside: right rotation first, left rotation 2nd, return top node
        node->right = rightRotate(node->right);
            return leftRotate(node);
     if no rotation, return node
   */
}

//non-tail recursive algorithm because of rebalance 
node* tree::insert(node* node, int key)
{
    //recursive Code for inserting a node 
    //When insert happens set height to 0 for the node     
    if (node == NULL) 
    {//don't need to account for the root node being null because the tree constructor
        //requires a node to start, and there's no remove function in this code
        node = new node(key);
        return(node);
    }
    if (key < node->key) 
    {
        node->left = insert(node->left, key);
    }
    else 
    {
        node->right = insert(node->right, key);
    }

    node = rebalance(node);  //update heights and rebalance
    return node;
}


node* tree::leftRotate(node* x) 
{
    node* y = x->right;
    //add more code to rotate to the left, update heights for x and y
    //return y
}


node* tree::rightRotate(node* x) 
{
    node* y = x->left;
    //add more code to rotate to the right, update heights for x and y  
    //return y
}


int tree::height(node* node) {

}


int tree::getBalance(node* node) {

}


void tree::print() 
{

}


int main()
{
    int data;
    ifstream numbersFile("numbers.txt");

    if (numbersFile.is_open()) {
        //create the tree to store numbers
        numbersFile >> data;
        node* root = new node(data);
        tree AVLTree(root);

        //while incoming data exists, insert into tree
        while (numbersFile >> data) {
            AVLTree.insert(root, data);
        }
        numbersFile.close();

        //test all functions here
        //open an output stream
        ofstream treeFile("tree.txt");
        //write tree

    }
    return 0;
}