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
  size=0;
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
    cout<<"Wartosc: "<<temp->data<<"\tKolor: "<<temp->color<<"\tOjciec: "<<temp->up->data<<endl;
    traversingTree(temp->right);
    traversingTree(temp->left); //traversing left subtree
  }
}
template<class T>
void tree<T>::showTree()
{
  //node * current=first;
  cout<<"Zawartosc drzewa:"<<endl;
  cout<<"---------------------------"<<endl;
  traversingTree(root);
  cout<<"---------------------------"<<endl;
  cout<<endl;
}

template<class T>
typename tree<T>::node * tree<T>::getNode(T val)
{
  node * temp;

  temp = root;
  while((temp != &dummy) && (temp->data != val))
    if(val < temp->data) temp = temp->left;
    else           temp = temp->right;
  if(temp == &dummy) return NULL;  //node not found
  return temp;
}

template<typename T>
void tree<T>::addNode(T val)
{
  node * newNode, * uncle; //uncle - brother of a parent - like in family tree
  newNode = new node;
  newNode->left=&dummy;
  newNode->right=&dummy;
  newNode->up=root;
  newNode->data=val;

  if (newNode->up == &dummy) //tree's empty
  {
    root=newNode;
    //root->color='b';
  }
  else
  {
    while (true)
    {
      if(val<newNode->up->data)
      {
        if (newNode->up->left == &dummy) //left leaf doesn't exist
        {
          newNode->up->left = newNode; // newNode becomes left leaf
          break;
        }
        newNode->up = newNode->up->left;
      }
      else
      {
        if(newNode->up->right == &dummy) //similarly
        {
          newNode->up->right = newNode;
          break;
        }
        newNode->up = newNode->up->right;
      }
    }
  }

  newNode->color = 'r';

  while((newNode != root) && (newNode->up->color == 'r')) //checking properties of Red-Black Tree
  {
    if(newNode->up == newNode->up->up->left)
    {
      uncle = newNode->up->up->right;

      if(uncle->color == 'r')  //newNode, parent and uncle are red
      {
        newNode->up->color = 'b'; //reversing colors
        uncle->color = 'b';
        newNode->up->up->color = 'r';
        newNode = newNode->up->up;
        continue;  //to check if grandparent can be red
      }

      if(newNode == newNode->up->right) //left-rotation case
      {
        newNode = newNode->up;
        leftRotation(newNode);
      }  //now parent is our newNode, right rotation needed

      // right-rotation case
      newNode->up->color = 'b'; //reversing colors
      newNode->up->up->color = 'r';
      rightRotation(newNode->up->up);
      break;
    }
    else
    {                  // mirror cases
      uncle = newNode->up->up->left;

      if(uncle->color == 'r')
      {
        newNode->up->color = 'b';
        uncle->color = 'b';
        newNode->up->up->color = 'r';
        newNode = newNode->up->up;
        continue;
      }

      if(newNode == newNode->up->left)
      {
        newNode = newNode->up;
        rightRotation(newNode);
      }

      newNode->up->color = 'b';
      newNode->up->up->color = 'r';
      leftRotation(newNode->up->up);
      break;
    }
  }
  root->color = 'b';
  size++;
} //addNode

template<typename T>
void tree<T>::leftRotation(node * x)  // before: y - right son of x
{
  node * y, * temp;
  y=x->right;
  if (y != &dummy)
  {
    temp = x->up;
    x->right = y->left;
    if(x->right != &dummy) x->right->up = x;

    y->left = x;
    y->up = temp;
    x->up = y;

    if(temp != &dummy)
    {
      if(temp->left == x) temp->left = y; else temp->right = y;
    }
    else root = y;
  } //after: x- left son of y
}

template<typename T>
void tree<T>::rightRotation(node * x)
{
  node * y, * temp;

  y = x->left;
  if(y != &dummy)
  {
    temp = x->up;
    x->left = y->right;
    if(x->left != &dummy) x->left->up = x;

    y->right = x;
    y->up = temp;
    x->up = y;

    if(temp != &dummy)
    {
      if(temp->left == x) temp->left = y; else temp->right = y;
    }
    else root = y;
  }
}

//TODO: give nodes prettier names
template<typename T>
void tree<T>::deleteNode(node * a)
{
  node * b, * c, * d;

  if((a->left == &dummy) || (a->right == &dummy)) b = a;
  else                                    b = succesor(a);

  if(b->left != &dummy) c = b->left;
  else              c = b->right;

  c->up = b->up;

  if(b->up == &dummy) root = c;
  else if(b == b->up->left) b->up->left  = c;
  else                      b->up->right = c;

  if(b != a) a->data = b->data;

  if(b->color == 'b')   // Naprawa struktury drzewa czerwono-czarnego
    while((c != root) && (c->color == 'b'))
      if(c == c->up->left)
      {
        d = c->up->right;

        if(d->color == 'r')
        {              // Przypadek 1
          d->color = 'b';
          c->up->color = 'r';
          leftRotation(c->up);
          d = c->up->right;
        }

        if((d->left->color == 'b') && (d->right->color == 'b'))
        {              // Przypadek 2
          d->color = 'r';
          c = c->up;
          continue;
        }

        if(d->right->color == 'b')
        {              // Przypadek 3
          d->left->color = 'b';
          d->color = 'r';
          rightRotation(d);
          d = c->up->right;
        }

        d->color = c->up->color; // Przypadek 4
        c->up->color = 'b';
        d->right->color = 'b';
        leftRotation(c->up);
        c = root;         // To spowoduje zakoñczenie pêtli
      }
      else
      {                // Przypadki lustrzane
        d = c->up->left;

        if(d->color == 'r')
        {              // Przypadek 1
          d->color = 'b';
          c->up->color = 'r';
          rightRotation(c->up);
          d = c->up->left;
        }

        if((d->left->color == 'b') && (d->right->color == 'b'))
        {              // Przypadek 2
          d->color = 'r';
          c = c->up;
          continue;
        }

        if(d->left->color == 'b')
        {              // Przypadek 3
          d->right->color = 'b';
          d->color = 'r';
          leftRotation(d);
          d = c->up->left;
        }

        d->color = c->up->color;  // Przypadek 4
        c->up->color = 'b';
        d->left->color = 'b';
        rightRotation(c->up);
        c = root;         // To spowoduje zakoñczenie pêtli
      }

  c->color = 'b';

  delete b;
  size--;
}

//TODO: the hell typename
template<typename T>
typename tree<T>::node * tree<T>::succesor(node * x)
{
  node * succesor;

  if(x != &dummy)
  {
    if(x->right != &dummy) return minimum();
    else
    {
      succesor = x->up;
      while((succesor != &dummy) && (x == succesor->right))
      {
        x = succesor;
        succesor = succesor->up;
      }
      return succesor;
    }
  }
  return &dummy;
}

template<typename T>
typename tree<T>::node * tree<T>::minimum()
{
  node * x;
  x=root;
  if(x != &dummy)
    while(x->left != &dummy) x = x->left;
  return x;
}


