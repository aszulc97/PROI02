/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#ifndef TREE_H_
#define TREE_H_
#include <iostream>

template <typename T>
class tree
{
    public:
      //template <typename T>
      class node
      {
        public:
          char color; // r-red, b-black
          node * up;
          node * left;
          node * right;
          T data;
      };

      tree(); //constructor
      ~tree(); //destructor
      void deleteTree(node * temp);
      void showTree();
      void traversingTree(node * temp);
      node * getNode(T val);
      void addNode(T val);
      void leftRotation (node * x);
      void rightRotation (node * x);
      void deleteNode(node * a);
      node * succesor(node * x);
      node * minimum();
      int size;

    private:
      node * root;
      node dummy; //dummy node contains every null node (leaf)
};



#endif //TREE_H_
