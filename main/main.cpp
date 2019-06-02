#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    srand(time (NULL));

    fstream plik;
    string dane;
    int num = 0;
    int wys = 10;
    int szer = 10;
    int liczba_slow = 15;


    plik.open("config.txt", std::ios::in | std::ios::out );
    if(plik.good())
    {
        getline(plik, dane);
        num = atoi(dane.c_str());

        getline(plik, dane);
        wys = atoi(dane.c_str());

        getline(plik, dane);
        szer = atoi(dane.c_str());

        getline(plik, dane);
        liczba_slow = atoi(dane.c_str());
    }

    plik.close();

    int wybor = 0;
    bool endOfProgram = false;

    string tab[num];

    char tablica_gry[wys][szer];
    int tablica_gry_I[wys][szer];


    while(endOfProgram == false)
    {
        cout<<"Wybierz odpowiednia opcje: "<<endl<<"1. Wgraj slowa ze slownika."<<endl<<"2. Posortuj slowa."<<endl<<"3. Generuj nowa plansze."<<endl<<"4. Szukaj wzorca."<<endl<<"7. Wyswietl aktualna plansze."<<endl<<"8. ZAPIS posortowanej tablicy do pliku"<<endl<<"9. Wyjscie z programu"<<endl;
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

                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");
            }
            break;

            case 2:{
                sort(tab, tab+num);

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

                int X1 = 0;
                int Y1 = 0;

                for(int i=0 ; i<wys ; i++)
                {
                    for(int j=0 ; j<szer ; j++)
                    {
                        tablica_gry[i][j] = '*';
                        tablica_gry_I[i][j] = 0;
                    }
                }

                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");


                bool next = false;
                bool poziomo = true;

                for(int i=0; i<liczba_slow; i++)
                {
                    next = false;
                    poziomo = true;
                    int numerWyrazu = rand()%200;
                    int rozmiar = tab[numerWyrazu].size();

                    while(!next)
                    {
                        if(poziomo)
                        {
                            X1 = rand()%(szer-rozmiar);
                            Y1 = rand()%(wys);
                        }
                        else
                        {
                            X1 = rand()%(szer);
                            Y1 = rand()%(wys - rozmiar);
                        }

                        if(poziomo)
                        {
                            int val = 0;
                            for(int z=X1; z<(X1+rozmiar); z++)
                            {
                                val = tablica_gry_I[Y1][z] + val;
                            }

                            if(val == 0)
                            {
                                string now;
                                now = tab[numerWyrazu];

                                for(int z=X1; z<(X1+rozmiar); z++)
                                {
                                    tablica_gry[Y1][z] = now[z-X1];
                                    tablica_gry_I[Y1][z] = 1;
                                    next = true;
                                }
                            }
                            poziomo = !poziomo;
                        }

                        if(!poziomo)
                        {
                            int val = 0;
                            for(int z=Y1; z<(Y1+rozmiar); z++)
                            {
                                val = tablica_gry_I[z][X1] + val;
                            }

                            if(val == 0)
                            {
                                string now;
                                now = tab[numerWyrazu];

                                for(int z=Y1; z<(Y1+rozmiar); z++)
                                {
                                    tablica_gry[z][X1] = now[z-Y1];
                                    tablica_gry_I[z][X1] = 1;
                                    next = true;
                                }
                            }
                            poziomo = !poziomo;
                        }
                    }
                }

               for(int i=0 ; i<wys ; i++)
               {
                    for(int j=0 ; j<szer ; j++)
                    {
                        cout<<tablica_gry[i][j];
                    }
                    cout<<endl;
                }


                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");

                 for(int i=0 ; i<wys ; i++)
                    {
                        for(int j=0 ; j<szer ; j++)
                        {
                            if(tablica_gry_I[i][j] == 0)
                            {
                                char temp = rand()%26 + 97;
                                tablica_gry_I[i][j] = 1;
                                tablica_gry[i][j] = temp;
                            }
                        }
                    }



                    for(int i=0 ; i<wys ; i++)
                    {
                        for(int j=0 ; j<szer ; j++)
                        {
                            cout<<tablica_gry[i][j];
                        }
                        cout<<endl;
                    }

                    cout<<"\n\nKliknij ENTER aby kontynuowac";
                    cin.ignore().get();
                    system("cls");

            }
            break;


            case 4:{

                string p,s;
                int rozmiar, licznik, ileZnaleziono = 0;

                for(int i=0 ; i<wys ; i++)
                {
                    for(int j=0 ; j<szer ; j++)
                    {
                        cout<<tablica_gry[i][j];
                    }
                    cout<<endl;
                }

                cout<<endl<<"Poziomo: "<<endl;

                for(int j=0; j<wys; j++)
                {

                    for(int i=0; i<szer; i++)
                    {
                        p[i] = tablica_gry[j][i];
                    }

                    for(int z=0; z<num; z++)
                    {
                        s = tab[z];
                        rozmiar = s.size();
                        licznik = 0;

                        for(int i=0; i<szer; i++)
                        {
                            if(p[i] == s[licznik])
                            {
                                licznik++;
                            }
                            else
                            {
                                licznik = 0;
                            }

                            if(licznik == rozmiar)
                            {
                                licznik = 0;
                                ileZnaleziono++;
                                cout<<"Znaleziono wyraz nr. "<<ileZnaleziono<<" w wierszu: "<<j+1<<" kolumnie: "<<i+2-rozmiar<<"  | "<<s<<endl;
                            }
                        }
                    }
                }

                cout<<endl<<"Pionowo: "<<endl;

                for(int j=0; j<szer; j++)
                {
                    for(int i=0; i<wys; i++)
                    {
                        p[i] = tablica_gry[i][j];
                    }

                    for(int z=0; z<num; z++)
                    {
                        s = tab[z];
                        rozmiar = s.size();
                        licznik = 0;

                        for(int i=0; i<wys; i++)
                        {
                            if(p[i] == s[licznik])
                            {
                                licznik++;
                            }
                            else
                            {
                                licznik = 0;
                            }

                            if(licznik == rozmiar)
                            {
                                ileZnaleziono++;
                                cout<<"Znaleziono wyraz nr. "<<ileZnaleziono<<" w wierszu: "<<i+2-rozmiar<<" kolumnie: "<<j+1<<"  | "<<s<<endl;
                                licznik = 0;
                                i = szer-1;
                                 z = num;
                            }
                        }
                    }
                }

                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");
            }
            break;

            case 7:{

            for(int i=0 ; i<wys ; i++)
            {
                for(int j=0 ; j<szer ; j++)
                {
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
                        plik<<tab[i];

                    }
                }
                plik.close();

                cout<<"\n\nKliknij ENTER aby kontynuowac";
                cin.ignore().get();
                system("cls");
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

int power_modulo_fast(int a, int b, int m)
{
    int i;
    int result = 1;
    long int x = a%m;

    for (i=1; i<=b; i<<=1)
    {
    x %= m;
    if ((b&i) != 0)
    {
    result *= x;
    result %= m;
    }
    x *= x;
    }

    return result%m;
}
