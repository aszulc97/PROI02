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
    myTree.addNode(22);
    myTree.addNode(7);
    myTree.addNode(8);
    myTree.addNode(10);
    myTree.addNode(11);
    myTree.showTree();
    return 0;
}
