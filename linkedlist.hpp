#pragma once
#include <iostream>
using namespace std;
/*
--------------A Data Structure Project-----------------------
--------------Tayvian Wallace & Mohamad Saatay---------------
--------------Tayvian was in charge of linked list implementation,as well as implementing the hashTables---------------
--------------Mohamad was in charge of BST implementation, linked list implementation------


*/
struct Node
{
    int key; // A node contains a key 
    Node * next; // node contains a next pointer
};

class Linked
{
    private:
    Node * head; // pointer to the head of the LL

    public:
    Linked(); // default contructor
    ~Linked(); 
    Node* search(int data); // function searched for a node
    void insert(int data); // inserts a node into a LL
    void prettyPrint(); // prints the LL

    
};