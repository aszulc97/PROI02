/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#ifndef TREE_H_
#define TREE_H_
#include <iostream>

template <class T>
class tree
{
    public:
      //template <typename T>
      class node
      {
          int key;
          char color; // r-red, b-black
          node * up;
          node * left;
          node * right;
          T data;
      };

      tree(); //constructor
      ~tree(); //destructor
      deleteTree(node * temp);
      showTree(node * first);
      traversingTree(node * temp);

    private:
      node * root;
      node dummy; //dummy node contains every null node (leaf)
      int size;
};



#endif //TREE_H_
