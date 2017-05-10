/**
* Name: Red-Black Tree
* Author: Agata Szulc
* 6.05.2017
*/

#include <iostream>
#include <windows.h>
#include "tree.h"
#include "tree.cpp"

int main()
{
  tree<int> myTree1;
  tree<int> myTree2;

  char choice, trig1=1, trig2=0;

  do
  {
    system("cls");
    if(trig1) myTree1.showTree();
    if(trig2) myTree2.showTree();
    cout<<"MENU:"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1. Dodaj nowy wezel"<<endl;
    cout<<"2. Usun wezel"<<endl;
    cout<<"3. Pokaz wezel"<<endl;
    cout<<"4. Dodaj nowe drzewo"<<endl;
    cout<<"5. Zsumuj drzewa"<<endl;
    cout<<"6. Skopiuj wezel"<<endl;
    cout<<"7. Sprawdz, czy wezel istnieje"<<endl;
    cout<<"8. Sprawdz rozmiar/y drzew/a"<<endl;
    cout<<"Wcisnij q, aby zakonczyc"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Twoj wybor: ";
    cin>>choice;

    switch(choice)
    {
      case '1':
        {
          char treeNumber;
          int newValue;
          if(trig2)
          {
            while(treeNumber!='1' && treeNumber!='2')
            {
              cout<<"Chcesz dodac wezel do drzewa 1 czy 2? Wpisz numer: ";
              cin>>treeNumber;
              if (treeNumber!='1' && treeNumber!='2')
              {
                cout<<"Nie ma takiego numeru!"<<endl;
                continue;
              }
              cout<<"Podaj wartosc nowego wezla: ";
              cin>>newValue;
              if (treeNumber=='1') myTree1.addNode(newValue);
              else myTree2.addNode(newValue);
            } treeNumber='0';
          }
          else
          {
            cout<<"Podaj wartosc nowego wezla: ";
            cin>>newValue;
            myTree1.addNode(newValue);
          }
        }break;
      case '2':
        {
          char treeNumber;
          int chosenValue;
          cout<<"Chcesz usunac element z drzewa 1 czy 2? Wpisz numer: ";
          cin>>treeNumber;
          if (treeNumber!='1' && treeNumber!='2') cout<<"Nie ma takiego numeru!"<<endl;
            else
            {
              cout<<"Podaj wartosc wezla, ktory chcesz usunac: ";
              cin>>chosenValue;
              if (treeNumber=='1') myTree1.deleteNode(myTree1.getNode(chosenValue));
              else myTree2.deleteNode(myTree2.getNode(chosenValue));
            }
        }break;
      case '3':
        {
          char treeNumber;
          int chosenValue;
          cout<<"Chcesz zobaczyc wezel z drzewa 1 czy 2? Wpisz numer: ";
          cin>>treeNumber;
            if (treeNumber!='1' && treeNumber!='2') cout<<"Nie ma takiego numeru!"<<endl;
            else
            {
              cout<<"Podaj wartosc elementu, ktory chcesz zobaczyc: "; //obs³uga blêdów!
              cin>>chosenValue;
              if (treeNumber=='1')
              {
                cout<<"Zawartosc: "<<myTree1.getNode(chosenValue)->data<<"\tKolor: ";
                if (myTree1.getNode(chosenValue)->color=='r') cout<<"Czerwony"<<endl;
                else cout<<"Czarny"<<endl;
              }
              else
              {
                cout<<"Zawartosc: "<<myTree2.getNode(chosenValue)->data<<"\tKolor: ";
                if (myTree2.getNode(chosenValue)->color=='r') cout<<"Czerwony"<<endl;
                else cout<<"Czarny"<<endl;
              }
            }
          Sleep(1000);
        }break;
      case '4':
        {
          trig2=1;
        }break;
      case '5':
        {
          for(int i=0; i<=myTree2.size; i++)
          {
            myTree1.addNode(myTree2.minimum()->data);
            myTree2.deleteNode(myTree2.minimum());
          }
        }break;
      case '6':
      {
        int chosenValue;
        char key;

        if(trig2)
        {
          cout<<"Podaj wartosc elementu, ktory chcesz skopiowac: ";
          cin>>chosenValue;
          if (myTree1.getNode(chosenValue) || myTree2.getNode(chosenValue))
          {
            while(key!='a' && key!='b')
            {
              cout<<"Chcesz go wkleic do..."<<endl;
              cout<<"a. Pierwszej listy"<<endl;
              cout<<"b. Drugiej listy"<<endl;
              cout<<"Wpisz a lub b: ";
              cin>>key;
              key=tolower(key);
              if (key!='a' && key!='b')
              {
                cout<<"Sprobuj ponownie"<<endl;
                continue;
              }
              if (key=='a') myTree1.addNode(chosenValue);
              else myTree2.addNode(chosenValue);
            }
          }
          else
          {
            cout<<"Nie ma takiego elementu";
            Sleep(2000);
          }
        }
        else
        {
          cout<<"Podaj wartosc elementu, ktory chcesz skopiowac: ";
          cin>>chosenValue;
          if (myTree1.getNode(chosenValue)) myTree1.addNode(chosenValue);
          else
          {
            cout<<"Nie ma takiego elementu";
            Sleep(2000);
          }
        }

      }break;
      case '7':
        {

        }break;
      case '8':
        {
          if (trig1) cout<<"Ilosc wezlow w pierwszym drzewie: "<<myTree1.size<<endl;
          if (trig2) cout<<"Ilosc wezlow w drugim drzewie: "<<myTree2.size<<endl;
          Sleep(2000);
        }break;
  //  case '9': comparisonOfTwo(); break;
      case 'q': break;
      default: cout<<"Sprobuj ponownie"; break;
    }
  } while (choice!='q');
return 0;
}
