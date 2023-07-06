#ifndef HASH_HPP
#define HASH_HPP
#pragma once
#include <string>


using namespace std;

struct node
{
    int key; // node contains a key
    struct node* next; // node contains a next pointer
};

class HashTable
{

    int tableSize = 40009; // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfcollision =0;
    node* createNode(int key, node* next); // has a key node should be NULL;
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    //node * insertItem(int key);

    // hash function to map values to key
   int hashFunction(int key);
    bool LinearProbe(int key);
    bool LinearSearch(int key);
    bool QuadraticProbe(int key);
    bool QuadSearch(int key);
    bool Chaining(int key);
    bool ChainSearch(int key);

    void printTable();
    int getNumOfCollision(); // collision occurs when two values share the same index // all indcies originally NULL

    node* searchItem(int key);
};

#endif
