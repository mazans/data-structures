#ifndef HEAP_H
#define HEAP_H

#include<string>

using std::string;

class Heap //Klasa implementujaca kopiec
{
private:
    int *table; //wskaznik na talice przechowujaca elementy kopca
    int size; //rozmiar kopca

    void show_helper(int ind, int depth, string branch); //metoda pomocnicza, przydatna przy wyswietlaniu kopca
public:
    Heap();
    ~Heap();

    void push(int elem); //dodanie do kopca elementu o zadanej wartosci
    void pop(); //usuniecie elementu ze szczytu

    int get_size(); //zwraca rozmiar kopca

    void show(); //wyswietla zawartosc kopca
    bool find(int n); //sprawdza czy w kopcu znajduje sie podany element n
};

#endif // HEAP_H
