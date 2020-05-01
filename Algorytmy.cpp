// Grille.cpp

#include <fstream>
#include <iostream>
#include <vector>


/**
 * Created by Kamil on 05.03.2020.
 */
   //1. pobierz jeden znak (N, jesli N = 0 to wyjdz z petli i zakoncz program)
   //2. pobierz N*N znakow i wczytaj je do tablicy wzoru
   //3. pobierz N*N znakow i wczytaj je do tablicy liter
   //4. porownaj tablice wzorow z tablica liter, jesli w tablicy wzoru jest 'O' to dodaj z drugiej tablicy litere do vectora
   //5. obroc tablice wzorow
   //6. wroc do punktu 4 (wykonaj to jeszcze dwa razy)
   //7. powrot do 1 punktu

int main()
{
    std::ifstream input("dane.txt");
    char data = '1';

    std::vector <char> haslo;

    //odczytywanie matrycy i liter
    while (true)
    {
        int size = 0;
        int n = 0;
        int m = 0;

        //pobranie wielkosci krawedzi matrycy
        input >> size;

        int warunekWykonaniaProgramu = size;
        if (warunekWykonaniaProgramu == 0)
            break;

        //matryca (tablica z O #)
        char** tab = new char* [size];
        for (int i = 0; i < size; i++)
            tab[i] = new char[size];

        //litery (tablica z literami ktore dadza haslo)
        char** tab2 = new char* [size];
        for (int i = 0; i < size; i++)
            tab2[i] = new char[size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                input >> tab[i][j];

            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                input >> tab2[i][j];

            }
        }

        //porownanie 2 tablic i dodanie do vectora liter z hasla
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (tab[i][j] == 'O')
                    haslo.push_back(tab2[i][j]);
            }
        }

        //przypisanie obroconej tablicy do tablicy pierwszy obrot
        char** pierwszyObrot = new char* [size];
        for (int i = 0; i < size; i++)
            pierwszyObrot[i] = new char[size];

        for (int i = 0; i < size; i++) {
            for (int j = 0, g = (size - 1); j < size; j++, g--) {
                pierwszyObrot[i][j] = tab[g][i];
            }
        }

        //porownanie 2 tablic po pierwszym obrocie i dodanie do vectora liter z hasla
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (pierwszyObrot[i][j] == 'O')
                    haslo.push_back(tab2[i][j]);
            }
        }


        //przypisanie obroconej tablicy do tablicy drugi obrot
        char** drugiObrot = new char* [size];
        for (int i = 0; i < size; i++)
            drugiObrot[i] = new char[size];

        for (int i = 0; i < size; i++) {
            for (int j = 0, g = (size - 1); j < size; j++, g--) {
                drugiObrot[i][j] = pierwszyObrot[g][i];
            }
        }

        //porownanie dwoch tablic po drugim obrocie i dodanie do vectora liter z hasla
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (drugiObrot[i][j] == 'O')
                    haslo.push_back(tab2[i][j]);
            }
        }

        //przypisanie obroconej tablicy do tablicy trzeci obrot
        char** trzeciObrot = new char* [size];
        for (int i = 0; i < size; i++)
            trzeciObrot[i] = new char[size];

        for (int i = 0; i < size; i++) {
            for (int j = 0, g = (size - 1); j < size; j++, g--) {
                trzeciObrot[i][j] = drugiObrot[g][i];
            }
        }

        //porownanie dwoch tablic po trzecim(ostatnim) obrocie i dodanie do vectora liter z hasla
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (trzeciObrot[i][j] == 'O')
                    haslo.push_back(tab2[i][j]);
            }
        }

        for (int i = 0; i < haslo.size(); i++)
            std::cout << haslo[i];

        std::cout << "\n";

        //zwalnianie pamieci
        for (int i = 0; i < size; i++)
            delete[] tab[i];

        delete[]  tab;

        for (int i = 0; i < size; i++)
            delete[] tab2[i];

        delete[]  tab2;

        for (int i = 0; i < size; i++)
            delete[] pierwszyObrot[i];

        delete[]  pierwszyObrot;

        for (int i = 0; i < size; i++)
            delete[] drugiObrot[i];

        delete[]  drugiObrot;

        for (int i = 0; i < size; i++)
            delete[] trzeciObrot[i];

        delete[]  trzeciObrot;

        //czyszczenie vectora
        haslo.clear();
    }

    input.close();

}