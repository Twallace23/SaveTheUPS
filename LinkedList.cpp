#include "linkedlist.hpp"
#include <iostream>
using namespace std;

Linked::Linked()
{
    head = NULL;
}

Linked::~Linked()
{
    for(Node*tmp = head; tmp!=0; tmp = tmp -> next) // iterate until you get to end of the list
    {
        delete tmp; // deletes the
    }
    head = NULL;

}

Node* Linked::search(int data)
{
    for(Node*tmp = head; tmp!=0; tmp = tmp -> next)
    {
        if(tmp->key==data) // if the key is found returns a pointer to that node
        {
            return tmp;
        }
    }
    return 0;
}

void Linked::insert(int data)
{
  Node * temp = new Node; // dynamic node creation
  temp -> key = data; // sets the key of a node to the int value
  temp -> next = NULL; // after temp the list is empty
  if(head==NULL) // if the list is empty
    {
    head = temp;
    return;
    }
    Node * point = head;
  while(point -> next !=NULL) // while not at the end of the list
     {
        point = point -> next; // point is iterating through the points

     }
     point -> next = temp;

}

void Linked::prettyPrint()
{
    cout << "[ ";
    Node * temp = head;
    while(temp!=NULL) // prints the list while its not empty
    {
        cout << temp -> key << " ";
        temp = temp -> next;
    }
    cout << " ]" << endl;
}
