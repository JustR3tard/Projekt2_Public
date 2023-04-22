
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

class samolot
{
public:
    int x;
    int y;
    bool direction;
    bool gora;
    bool dol;
    int ruchy;
    bool tura = false;
    char ID = NULL;
    int Numer = 0;
    samolot(int copy[][20], char* name, int* numer)
    {
       
        srand(time(NULL));
        y = rand() % 10;
        direction = rand() % 2;
        if (direction)
        {
            x = 0;
        }
        else x = 19;
        bool poprawne = false;
        do
        {
            if (copy[y][x] == 0)
            {
                if (x == 0)
                {
                    if (y == 0)
                    {
                        if (copy[y + 1][x] == 0 && copy[y][x + 1] == 0)
                        {
                            poprawne = true;
                        }
                        else
                        {
                            y = rand() % 10;
                            direction = rand() % 2;
                            if (direction)
                            {
                                x = 0;
                            }
                            else x = 19;
                        }
                    }
                    if (y == 9)
                    {
                        if (copy[y - 1][x] == 0 && copy[y][x + 1] == 0)
                        {
                            poprawne = true;
                        }
                        else
                        {
                            y = rand() % 10;
                            direction = rand() % 2;
                            if (direction)
                            {
                                x = 0;
                            }
                            else x = 19;
                        }
                    }
                    if (y > 0 && y < 9)
                    {
                        if (copy[y + 1][x] == 0 && copy[y - 1][x] == 0)
                        {
                            if (copy[y][x + 1] == 0)
                                poprawne = true;
                            else
                            {
                                y = rand() % 10;
                                direction = rand() % 2;
                                if (direction)
                                {
                                    x = 0;
                                }
                                else x = 19;
                            }
                        }
                        else
                        {
                            y = rand() % 10;
                            direction = rand() % 2;
                            if (direction)
                            {
                                x = 0;
                            }
                            else x = 19;
                        }
                    }
                }
                if (x == 19)
                {
                    if (y == 0)
                    {
                        if (copy[y + 1][x] == 0 && copy[y][x - 1] == 0)
                        {
                            poprawne = true;
                        }
                        else
                        {
                            y = rand() % 10;
                            direction = rand() % 2;
                            if (direction)
                            {
                                x = 0;
                            }
                            else x = 19;
                        }
                    }
                    if (y == 9)
                    {
                        if (copy[y - 1][x] == 0 && copy[y][x - 1] == 0)
                        {
                            poprawne = true;
                        }
                        else
                        {
                            y = rand() % 10;
                            direction = rand() % 2;
                            if (direction)
                            {
                                x = 0;
                            }
                            else x = 19;
                        }
                    }
                    if (y > 0 && y < 9)
                    {
                        if (copy[y + 1][x] == 0 && copy[y - 1][x] == 0)
                        {
                            if (copy[y][x - 1] == 0)
                                poprawne = true;
                            else
                            {
                                y = rand() % 10;
                                direction = rand() % 2;
                                if (direction)
                                {
                                    x = 0;
                                }
                                else x = 19;
                            }
                        }
                        else
                        {
                            y = rand() % 10;
                            direction = rand() % 2;
                            if (direction)
                            {
                                x = 0;
                            }
                            else x = 19;
                        }
                    }
                }
            }
            else
            {
                y = rand() % 10;
                direction = rand() % 2;
                if (direction)
                {
                    x = 0;
                }
                else x = 19;
            }

        } while (!poprawne);
        ID = *name;
        Numer = *numer;
        gora = false;
        dol = false;
        ruchy = 0;
        *name = *name + 1;
        *numer = *numer + 1;
        //samolotki.push_back();
        cout << x << " " << y << " " << ID << endl;
    }
    
    ~samolot()
    {
        cout << "samolot zniszczony " << ID << endl;
    }

};
void Map0(int copy[][20]);
void Map(int copy[][20], vector<samolot*>* samolotki);
void MapVis(int copy[][20] , vector<samolot*>* samolotki);
void Input(char* which, bool* Pause, char* order, int* amount);
void InputIn(char* which, char* order, int* amount, vector<samolot*>* samolotki);
void Real(int copy[][20], vector<samolot*>* samolotki);
void Continue(int copy[][20], vector<samolot*>* samolotki);
void BlowUp(int copy[][20], vector<samolot*>* samolotki);
int main()
{
    int air[10][20];
    char Which, Order;
    int Amount;
    bool Pause = false;
    
    Map0(air);
    char Name = 'A';
    int Numer = 1;
    int gene;
    vector<samolot*> samoloty;
    


    while (true)
    {
       gene = rand() % 4;
       if (!gene)
       {
            samolot* A = new samolot(air, &Name, &Numer);
            samoloty.push_back(A);

       }
        cout << "rozmiar tablicy to " << samoloty.size() << endl;
        BlowUp(air, &samoloty);
        Map(air, &samoloty);
        MapVis(air, &samoloty);
        for (int  i = 0; i < 10; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << air[i][j];
            }
            cout << endl;
        }
     
        cout << samoloty.size() << endl;
        while(!Pause)
        {

        Input(&Which, &Pause, &Order, &Amount);
        InputIn(&Which, &Order, &Amount, &samoloty);
        Which = NULL;
        Order = NULL;
        Amount = NULL;
        
        }
        Pause = false;
       
        Real(air, &samoloty);
        Continue(air, &samoloty);
       
        system("CLS");
        
    }
  

    return 0;
}
void Map0(int copy[][20])
{
    for (size_t i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++) {
            copy[i][j] = 0;
        }
    }
}
void Map(int copy[][20], vector<samolot*>* samolotki)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            for ( int k = 0; k < (*samolotki).size();  k++)
            {
                if ((*samolotki)[k]->x == j && (*samolotki)[k]->y == i)
                {
                    copy[i][j] = (*samolotki)[k]->Numer;
                }
            }
          
        }
    }
}
void MapVis(int copy[][20], vector<samolot*>* samolotki)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(copy[i][j]==0)
            {
                if (j == 0 || j == 19)
                {
                   cout << setw(5) << "|";
                }
                else cout << setw(5) << " ";
            }
            else
            {
                for (int k = 0; k < (*samolotki).size(); k++)
                {
                    if ((*samolotki)[k]->x == j && (*samolotki)[k]->y == i)
                    {
                        if ((*samolotki)[k]->direction)
                        {
                            cout << "(" << (*samolotki)[k]->ID << (*samolotki)[k]->ruchy << ")";
                            if ((*samolotki)[k]->gora)
                            {
                                cout << "/";
                            }
                            else if ((*samolotki)[k]->dol)
                            {
                                cout << "\\";
                            }
                            else
                            {
                                cout << "=";
                            }
                        }
                        else
                        {
                            if ((*samolotki)[k]->gora)
                            {
                                cout << "/";
                            }
                            else if ((*samolotki)[k]->dol)
                            {
                                cout << "\\";
                            }
                            else
                            {
                                cout << "=";
                            }
                            cout << setw(1) << "(" << (*samolotki)[k]->ID << (*samolotki)[k]->ruchy << ")";
                        }
                        
                    }
                }
            }
        }
            cout << endl;
    }
}
void Input(char* which, bool* Pause, char* order, int* amount)
{
    string input;
    cout << "podaj polecenie i zatwierdz enterem, znak spacji zatwierdzony enterem rozpocznie kolejna ture " << endl;
    do
    {

    getline(cin, input);
    } while (input=="");
   // cin >> input;
    if (input[0]!=32)
    {
        *which = input[0];
        *order = input[1];
        *amount = input[2]-'0';
    }
    else *Pause = true;
}
void InputIn(char* which, char* order, int* amount, vector<samolot*>* samolotki)
{
    for (int i = 0; i < (*samolotki).size(); i++)
    {
        if (*which == (*samolotki)[i]->ID)
        {
            if (*order == 'c')
            {
                (*samolotki)[i]->ruchy = 0;
                (*samolotki)[i]->gora = false;
                (*samolotki)[i]->dol = false;

            }
            if ((*samolotki)[i]->ruchy == 0)
            {
                if (*order == '/') 
                {
                    (*samolotki)[i]->gora = true;
                    (*samolotki)[i]->ruchy = *amount;
                }
                else if (*order == '\\')
                {
                    (*samolotki)[i]->dol = true;
                    (*samolotki)[i]->ruchy = *amount;
                }
            }
            else cout << "ten samolot juz ma rozkazy" << endl;
            
        }
       
    }
}
void Real(int copy[][20], vector<samolot*>* samolotki)
{
    int y;
    for (int i = 0; i < (*samolotki).size(); i++)
    {
        if ((*samolotki)[i]->gora && (*samolotki)[i]->tura)
        {
            if ((*samolotki)[i]->y != 0)
            {
                if ((*samolotki)[i]->ruchy > 0)
                {
                    y = (*samolotki)[i]->y;
                    (*samolotki)[i]->y = ((*samolotki)[i]->y - 1);
                    copy[y][(*samolotki)[i]->x] = 0;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = (*samolotki)[i]->Numer;
                    (*samolotki)[i]->ruchy = ((*samolotki)[i]->ruchy - 1);
                   
                }
                    if ((*samolotki)[i]->ruchy == 0)
                    {
                        (*samolotki)[i]->gora = false;
                    }
                    (*samolotki)[i]->tura = false;
            }


        }
        if ((*samolotki)[i]->dol)
        {
            if ((*samolotki)[i]->y != 9&& (*samolotki)[i]->tura)
            {
                if ((*samolotki)[i]->ruchy > 0)
                {
                    y = (*samolotki)[i]->y;
                    (*samolotki)[i]->y = ((*samolotki)[i]->y + 1);
                    copy[y][(*samolotki)[i]->x] = 0;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = (*samolotki)[i]->Numer;
                    (*samolotki)[i]->ruchy = ((*samolotki)[i]->ruchy - 1);
             
                }
                    if ((*samolotki)[i]->ruchy == 0)
                    {
                        (*samolotki)[i]->dol = false;
                    }
                    (*samolotki)[i]->tura = false;
            }
      
        }
    }
}
void Continue(int copy[][20], vector<samolot*>*samolotki)
{
    int x;
    for (int i = 0; i < (*samolotki).size(); i++)
    {
        
            if ((*samolotki)[i]->direction)
            {

                if ((*samolotki)[i]->x >= 19)
                {
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                   
                }
                else
                {
                    x = (*samolotki)[i]->x;
                    (*samolotki)[i]->x = ((*samolotki)[i]->x + 1);
                    copy[(*samolotki)[i]->y][x] = 0;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = (*samolotki)[i]->Numer;
                    (*samolotki)[i]->tura = true;

                }
                  
               
            }
            else
            {
              
                if ((*(*samolotki)[i]).x <= 0)
                {
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                   
                   
                    
 
                }
                else
                {
                    x = (*samolotki)[i]->x;
                    (*samolotki)[i]->x = ((*samolotki)[i]->x - 1);
                    copy[(*samolotki)[i]->y][x] = 0;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = (*samolotki)[i]->Numer;
                    (*samolotki)[i]->tura = true;

                }
                 
            }
       
        
    }
}
void BlowUp(int copy[][20], vector<samolot*>* samolotki)
{
    for (int i = 0; i < (*samolotki).size(); i++)
    {
        if (((*samolotki)[i]->x > 0 && (*samolotki)[i]->x < 19) && ((*samolotki)[i]->y > 0 && (*samolotki)[i]->y < 9))
        {
            // srodek
            if (copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x - 1] != 0)
            {
                cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                delete (*samolotki)[i];
                (*samolotki).erase((*samolotki).begin() + i);
               
            }
        }
        else if ((*samolotki)[i]->x == 0) // lewa strona
        {
            if ((*samolotki)[i]->y == 0) // gorny lewy skos
            {
                if (copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x + 1] != 0)
                {
                    cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                }
            }
            else if ((*samolotki)[i]->y == 9) // dolny lewy
            {
                if (copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x + 1] != 0)
                {
                    cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                }
            }
            else if ((*samolotki)[i]->y < 9 && (*samolotki)[i]->y > 0) // lewa sciana
            {
                if (copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y+1][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y+1][(*samolotki)[i]->x] != 0)
                {
                    cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                }
            }
        }
        else if ((*samolotki)[i]->x == 19) // prawa strona
        {
            if ((*samolotki)[i]->y == 0) // gorny prawy skos
            {
                if (copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x - 1] != 0)
                {
                    cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                }
            }
            else if ((*samolotki)[i]->y == 9) // dolny prawy
            {
                if (copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x - 1] != 0)
                {
                    cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                }
            }
            else if ((*samolotki)[i]->y < 9 && (*samolotki)[i]->y > 0) // prawa sciana
            {
                if (copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x] != 0)
                {
                    cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                    copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                    delete (*samolotki)[i];
                    (*samolotki).erase((*samolotki).begin() + i);
                }
            }
        }
        else if ((*samolotki)[i]->y == 0)
        {
            if (copy[(*samolotki)[i]->y][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y + 1][(*samolotki)[i]->x - 1] != 0) // gora
            {
                cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                delete (*samolotki)[i];
                (*samolotki).erase((*samolotki).begin() + i);
            }
        }
        else if ((*samolotki)[i]->y == 9)
        {
            if (copy[(*samolotki)[i]->y][(*samolotki)[i]->x - 1] != 0 || copy[(*samolotki)[i]->y][(*samolotki)[i]->x + 1] != 0 || copy[(*samolotki)[i]->y - 1][(*samolotki)[i]->x - 1] != 0) // gora
            {
                cout << "samolot o indexie " << (*samolotki)[i]->ID << "zostal zniszczony" << endl;
                copy[(*samolotki)[i]->y][(*samolotki)[i]->x] = 0;
                delete (*samolotki)[i];
                (*samolotki).erase((*samolotki).begin() + i);
            }
        }
        

    }
}
