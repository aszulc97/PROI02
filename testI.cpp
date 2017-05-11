#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "tree.h"
#include "testI.h"
#include "tree.cpp"
using namespace std;

void integerTest::testInterface()
{
  tree<int> myTree1;
  tree<int> myTree2;

  system("cls");
  cout<<"Dodajemy do drzewa pare elementow..."<<endl;
  myTree1.addNode(1);
  myTree1.addNode(14);
  myTree1.addNode(4);
  myTree1.addNode(9);
  myTree1.addNode(11);
  myTree1.addNode(3);
  myTree1.addNode(22);
  myTree1.addNode(6);
  getchar();
  myTree1.showTree();

  cout<<"Ile to wezlow?"<<endl;
  cout<<myTree1.size<<endl;
  getchar();

  system("cls");
  myTree1.showTree();
  cout<<"Usunmy 4 i sprawdzmy rezultaty"<<endl;
  cout<<endl;
  getchar();
  myTree1.deleteNode(myTree1.getNode(4));
  myTree1.showTree();

  getchar();
  system("cls");
  cout<<"Pora uruchomic drugie drzewo"<<endl;
  myTree1.showTree();
  myTree2.showTree();

  cout<<"I cos do niego dodac..."<<endl;
  getchar();
  system("cls");
  myTree2.addNode(5);
  myTree2.addNode(10);
  myTree2.addNode(3);
  myTree2.addNode(12);

  myTree1.showTree();
  myTree2.showTree();
  getchar();

  cout<<"Na koniec zsumujmy oba drzewa"<<endl;
  getchar();
  for(int i=0; i<=myTree2.size; i++)
  {
    myTree1.addNode(myTree2.minimum()->data);
    myTree2.deleteNode(myTree2.minimum());
  }

  myTree1.showTree();
}
