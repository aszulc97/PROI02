/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#include <iostream>
#include "tree.h"
#include "tree.cpp"

int main()
{
    tree<int> myTree;
    myTree.addNode(12);
    myTree.addNode(15);
    myTree.showTree();
    return 0;
}
