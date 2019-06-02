#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <algorithm>
#define MAX 100
#include <ctime>
#include <cmath>

using namespace std;

void menu()
{
    srand(time (NULL));

    int liczba = rand()%200;
    cout<<liczba;

    fstream plik;
    string dane;
    int num = 0;
    int wys = 10;
    int szer = 10;
    int liczba_slow = 1;


    plik.open("config.txt", std::ios::in | std::ios::out );
    if(plik.good())
    {
        getline(plik, dane);
        num = atoi(dane.c_str());

        getline(plik, dane);
        wys = atoi(dane.c_str());

        getline(plik, dane);
        szer = atoi(dane.c_str());
    }

    plik.close();

    int wybor = 0;
    bool endOfProgram = false;

    string tab[num];


    while(endOfProgram == false)
    {
        cout<<"Wybierz odpowiednia opcje: "<<endl<<"1. Wgraj slowa ze slownika"<<endl<<"2. Posortuj slowa"<<endl<<"3. Start"<<endl<<"8. ZAPIS posortowanej tablicy do pliku"<<endl<<"9. Wyjscie z programu"<<endl;
        cin>>wybor;

        switch(wybor){
            case 1:{

                    plik.open("slownik.txt", std::ios::in | std::ios::out );

                    if( plik.good() == true)
                    {
                        for(int i = 0; i<num; i++)
                        {
                            getline(plik, dane);
                            tab[i] = dane;
                            cout<<dane<<endl;
                        }
                    }
                    plik.close();


            }
            break;

            case 2:{

            sort(tab, tab+200);

            for(int i = 0 ; i < num; i++)
            {
                cout<<tab[i]<<endl;
            }

                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");
            }
            break;

            case 3:{

                char tablica_gry[wys][szer];
                int tablica_gry_I[wys][szer];

                for(int i=0 ; i<wys ; i++)
                {
                    for(int j=0 ; j<szer ; j++)
                    {
                        tablica_gry[i][j] = '*';
                        tablica_gry_I[i][j] = 0;
                        cout<<tablica_gry[i][j];
                    }
                    cout<<endl;
                }



                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");
            }
            break;

            case 8:{
                plik.open("posortowany_slownik.txt", std::ios::in | std::ios::out );
                if( plik.good() == true)
                {
                    for(int i = 0; i<num; i++)
                    {
                        plik<<tab[i]<<"/n";

                    }
                }
                plik.close();
            }
            break;

            case 9:{
                cout<<endl<<"Dzieki ze tutaj zajrzales! ";
                endOfProgram = true;
            }
            break;

            default:{
                cout<<endl<<"BLAD! Wybierz inny przycisk!";
            }
            break;
        }
    }
}
