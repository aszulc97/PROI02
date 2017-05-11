#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "tree.h"
#include "testC.h"
#include "tree.cpp"
using namespace std;

void characterTest::testInterface()
{
  tree<char> myTree1;
  tree<char> myTree2;

  system("cls");
  cout<<"Dodajmy do drzewa pare elementow..."<<endl;
  myTree1.addNode('m');
  myTree1.addNode('g');
  myTree1.addNode('z');
  myTree1.addNode('k');
  myTree1.addNode('v');
  myTree1.addNode('d');
  myTree1.addNode('a');
  myTree1.addNode('q');
  myTree1.addNode('n');
  getchar();
  myTree1.showTree();

  cout<<"Ile to wezlow?"<<endl;
  cout<<myTree1.size<<endl;
  getchar();

  system("cls");
  myTree1.showTree();
  cout<<"Usunmy v i sprawdzmy rezultaty"<<endl;
  cout<<endl;
  getchar();
  myTree1.deleteNode(myTree1.getNode('v'));
  myTree1.showTree();

  getchar();
  system("cls");
  cout<<"Pora uruchomic drugie drzewo"<<endl;
  myTree1.showTree();
  myTree2.showTree();

  cout<<"I cos do niego dodac..."<<endl;
  getchar();
  system("cls");
  myTree2.addNode('j');
  myTree2.addNode(':');
  myTree2.addNode('e');
  myTree2.addNode('{');

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
