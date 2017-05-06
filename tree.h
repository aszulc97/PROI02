#IFNDEF TREE_H_
#DEFINE TREE_H_
#include <iostream>

class Tree
{
    public:
      template <class T>
      class node
      {
          int key;
          char color // r-red, b-black
          node * up;
          node * left;
          node * right;
          T data;
      }

      tree(T content); //constructor
      ~tree(); //destructor

    private:
      node * root;
      int size;
}



#ENDIF TREE_H_
