/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#include <iostream>
#include "tree.h"
using namespace std;

template<typename T>
tree<T>::tree() //contains only dummy node
{
  dummy.color='b';
  dummy.data=NULL;
  dummy.up=&dummy;
  dummy.left=&dummy;
  dummy.right=&dummy;
  root=&dummy;
  size=1;
}

template<class T>
tree<T>::~tree()
{
  deleteTree(root);
}

template<class T>
void tree<T>::deleteTree(node * temp)  //recursion
{
  if (temp!=&dummy)
  {
    deleteTree(temp->left); //deleting left subtree
    deleteTree(temp->right);
    delete temp;
  }
}

template<class T>
void tree<T>::traversingTree(node * temp)
{
  if(temp != &dummy)
  {
    cout<<"Node data: "<<temp->data<<"\t"<<"Color: "<<temp->color<<"\t"<<"Parent: "<<temp->up->data;
    traversingTree(temp->left); //traversing left subtree
    traversingTree(temp->right);
  }
}
template<class T>
void tree<T>::showTree()
{
  //node * current=first;
  cout<<"Zawartosc drzewa:"<<endl;
  cout<<"---------------------------"<<endl;
  traversingTree(root);
  cout<<endl<<"---------------------------"<<endl;
}

//template<class T>
//typename tree<T>::node * tree<T>::findNode(node * temp, T val);

template<typename T>
void tree<T>::addNode(T val)
{
  node * newNode;
  newNode = new node;
  newNode->left=&dummy;
  newNode->right=&dummy;
  newNode->up=root;
  newNode->data=val;

  if (newNode->up == &dummy)
  {
    root=newNode;
    root->color='b';
  }
  else newNode->color='r';
}
