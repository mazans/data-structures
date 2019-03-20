#ifndef LIST_H
#define LIST_H

#include <iostream>

class List //klasa implementujaca liste dwukierunkowa
{

private:
    struct Element //struktura bedaca kolejnymi elementami listy
    {
        int data; //faktyczne przechowywane dane
        Element* next; // wskaznik na nastepny element listy
        Element* prev; //wskaznik na poprzedni element listy
    };
    Element* head; //glowa listy
    Element* tail; //ogon listy

    int size;
public:
    List();
    ~List();

    void push_front(int n); //wstawia element n na poczatek listy
    void pop_front(); //usuwa pierwszy elemet w liscie

    void push_back(int n); //wstawia element n na koniec listy
    void pop_back(); //usuwa ostatni element na liscie

    int get_size(); //zwraca rozmiar listy

    void push(int ind, int n); //wstawia element n na pozycje ind;
    void pop(int ind); //usuwa element z pozycji ind

    bool find(int k); //spawdza czy w liscie znajduje sie podany element k

    void show(); //pokazuje zawartosc listy
};

#endif // LIST_H
