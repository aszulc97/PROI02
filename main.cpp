/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#include <iostream>
#include <windows.h>
#include "tree.h"
#include "user.h"
#include "testI.h"
#include "testC.h"
using namespace std;


int main()
{
  char firstChoice, secondChoice;
  userVersion user;
  integerTest testI;
  characterTest testC;

  cout<<"Zabawa czy testy?"<<endl;
  cout<<"1. Zabawa"<<endl;
  cout<<"2. Testy"<<endl;
  cin>>firstChoice;

  if (firstChoice=='1') user.userInterface();
  else
  {
    system("cls");
    cout<<"Dzis nasze drzewa beda przechowywac:"<<endl;
    cout<<"1. Liczby"<<endl;
    cout<<"2. Znaki"<<endl;
    cin>>secondChoice;

    if (secondChoice=='1') testI.testInterface();
    else testC.testInterface();
    {

    }
  }
  return 0;
}
