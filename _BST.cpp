#include "_BST.hpp"
#include <iostream>
#include <string>
using namespace std;
#include "_BST.hpp"
#include <iostream>
#include <string>
using namespace std;
//default constructor
BST::BST()
{
    root = NULL;
}
//recursive helper for the insert function
Node* insertHelper(int k,Node*r)
{
    //new node to insert
    Node* fresh = new Node;
    //if root = NULL (tree is empty)
    if(r == NULL)
    {
        //then the new root is the new node
        r = fresh;
        //give the root the new key
        r->key = k;
        return r;
    }
    //if the key you are inserting is greater than root's key go right
    if(k>r->key)
    {
        r->right = insertHelper(k, r->right);
    }
    //if it's less go left
    else{
        r->left = insertHelper(k,r->left);
    }
    //return the new root
    return r;
}
void BST::insert(int k)
{
    //call the helper function to make the insertion and give root the value
    root = insertHelper(k,root);
}
//recursive helper function for the search function
Node* helper(Node* r, int k)
{
    //if tree is empty
    if(r==NULL)
    {
        return NULL;
    }
    //if the node you are looking for is the root
    if(r->key == k)
    {
        return r;
    }
    //if the node you are looking for has a value less than the root go left
    if(k<r->key)
    {
        return helper(r->left,k);
    }
    //if the node you are looking for has a value greater than the root go left
    if(k>r->key)
    {
        return helper(r->right, k);
    }
    //if node is not found
    return NULL;
}
void BST::search(int k)
{
    //make a new node and set it equal to the one you are looking for
   Node* fresh = helper(root,k);
   //if tree is empty
   if(root==NULL)
   {
       return;
   }
   //if node is not found 
   else if(fresh == NULL)
   {
       cout << "Node not found" << endl;
   }
    //if found then print it
   else{
       cout << fresh->key << endl;
   }

}
//recursive helper function to print tree in inorder
void inorderDisplay(Node* temp)
{
    //tree is empty
    if(temp==NULL)
    {
        return;
    }
    //call left to print left first
    inorderDisplay(temp->left);
    //print root
    cout << temp->key << " ";
    //go right to print right
    inorderDisplay(temp->right);

}
void BST::print()
{
    //just call the helper function to print
    inorderDisplay(root);
}