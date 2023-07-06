#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef BST_H
#define BST_H

struct Node
{
    int key;
    Node* left;
    Node* right;

};
class BST
{
    public:
    BST();
    //~BST();
    void insert(int);
    void search(int);
    //void print(string);
    void print();

    private:
    Node* root;
};



#endif