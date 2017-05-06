/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#include <iostream>
#include "tree.h"
using namespace std;

template<class T>
tree<T>::tree() //contains only dummy node
{
  dummy->color='b';
  dummy->data=NULL;
  dummy->key=NULL;
  dummy->up=&dummy;
  dummy->left=&dummy;
  dummy->right=&dummy;
  root=&dummy;
  size=1;
}

template<class T>
tree<T>::~tree()
{
  deleteTree(root);
}

template<class T>
tree<T>::deleteTree(node * temp)  //recursion
{
  if (temp!=&dummy)
  {
    deleteTree(temp->left); //deleting left subtree
    deleteTree(temp->right);
    delete temp;
  }
}

template<class T>
tree<T>::traversingTree(node * temp)
{
  if(temp)
  {
    cout<<temp->key<<" ";
    traversingTree(temp->left); //traversing left subtree
    traversingTree(temp->right);
  }
}
template<class T>
tree<T>::showTree(node * first)
{
  node * current=first;
  cout<<"Zawartosc drzewa:"<<endl;
  cout<<"---------------------------"<<endl;
  for (int i=0; i<size; i++)
  {
    current.refer->id=i+1;
    //gotoxy(300,200);
    cout << "Id: " << current.refer->id << "\tLiczba: " << current.refer->value << "\tIlosc dostepow: " << current.refer->access << "\n";
    current.refer=current.refer->next;
  }
cout<<"---------------------------"<<endl;
}
