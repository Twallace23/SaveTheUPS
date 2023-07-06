#include "hash.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
using namespace std;


 int HashTable::hashFunction(int key) //takes a key and returns the remainder after division
{
    return key % tableSize;

}

int HashTable::getNumOfCollision()
{
    int hash;
    int indice = hashFunction(hash); // hashFunction genrates an index
    for(int i=0; i < tableSize; ++i)
    {
        if(table[i]==table[indice]) // if the indice is equal to the position at I there is a colision
        {
            numOfcollision++; // increments the colision counter
        }
    }
return numOfcollision; // i
}

HashTable::HashTable(int size)
{
    tableSize = size;
   table = new node * [size]; // dynamically allocate a table with size of 40009
   for(int i=0; i < tableSize; i++)
   {
       table[i]=0; // sets all the values to NULL or 0
   }
  // cout << "you did it!" << endl;
}

node * HashTable::createNode(int key, node * next)
{

   node * temp = new node; // dynamically creates a node
   temp -> key = key; // nodes key is the int value
   temp -> next = next; // nodes next is the next value
   return temp; // returns a pointer to the node
}



 void HashTable::printTable()
{
      for(int i=0; i < tableSize; ++i)
      {
          if(table[i]!=0) // if table index isnt 0 meaning if the table has a value
          {
              cout << "well done!" << endl;
              cout << table[i] -> key << endl;
              cout << ".........." << endl;
          }
      }
}

bool HashTable::LinearProbe(int key)
{
    int count = 0;
    while(table[hashFunction(key+ count)] != 0) // count increments the table index and places an element in the next available position
    {
        count ++; // increments count // how the index changes
    }
    table[hashFunction(key+count)] = createNode(key,NULL); // creates a node with a key and a next pointer of NULL


    if(count != 0) // if a colision
    {
        numOfcollision++; 
        return false; 
    }
    //cout << "Item has been inserted " << endl;
    return true;
}

bool HashTable::LinearSearch(int key)
{
    int count = 0;
    while(table[hashFunction(key+count)] -> key != key) // searches a key and if not equal continues search
    {
        count++;

    }
    return true; // if key is found returns true
}

bool HashTable::QuadraticProbe(int key)
{
    int count = 0;

        while(table[hashFunction(key + pow(count,2))] != NULL) // same as linear except count is now squared 
        {
            count++;
        }
        table[hashFunction(key + pow(count,2))] = createNode(key,NULL);  // creates a key node who points to null

        if(count!=0)
        {
            numOfcollision++;
            return false;
        }
        //cout << "Cabs are here" << endl;
        return true;
}

bool HashTable::QuadSearch(int key)
{
    int count = 0;
    while(table[hashFunction(key+ pow(count,2))] -> key != key) // attempts to search for a key and if not found keeps searching
    {
        count++;
    }
    //cout << "cabs are leaving" << endl;
    return true; // if key is found returns true;
}


bool HashTable::Chaining(int key)
{
    int count = 0;
    node * temp = new node; // dynamic node allocation
    int hashIndex = hashFunction(key); // creates index from hashFunction
        if(table[hashIndex]== NULL) // if the index  isnt 0 creates a node
        {
            table[hashIndex] = createNode(key, temp ->next);
        }
        else
        {
            temp = table[hashIndex]; // creates the node branching out of the HashTable
            count++;
            while(temp -> next != NULL) // while the LL isnt emoty
            {
                temp = temp -> next; // increment the node
            }
            temp -> next = createNode(key,temp ->next); // creates a node if two values shar same index
        }

        if(count !=0)
        {
            numOfcollision++;
            return false;
        }
       // cout << "yeah buddy" << endl;
        return true;
}

bool HashTable::ChainSearch(int key)
{
    //int count = 0;
    int hashIndex = hashFunction(key);
    node * temp = table[hashIndex]; // creates a pointer to the table
    while(temp-> key != key) // loops through while the key isnt found
    {
        if(temp -> key == key ) // if the key is found return true
        {
            return true;
        }
       temp = temp -> next;

    }
    return false;
}

















