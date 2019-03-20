#ifndef TABLE_H
#define TABLE_H

class Table //klasa implemenujaca tabllice o zmiennym rozmiarze
{
private:
    int* table; //wskaznik na tablice o zmiennym rozmiarze
    int size; //rozmiar tablicy
public:
    Table();
    ~Table();

    void push_front(int n); //wstawia element n na poczatek tablicy
    void pop_front(); //usuwa pierwszy elemet w tablicy

    void push_back(int n); //wstawia element n na koniec tablicy
    void pop_back(); //usuwa ostatni element na tablicy

    int get_size(); //zwraca rozmiar tablicy

    void push(int ind, int n); //wstawia element n na pozycje ind;
    void pop(int ind); //usuwa element z pozycji ind

    bool find(int k); //sprawdza czy w tablicy znajduje sie podany element k

    void show(); //pokazuje zawartosc listy
};

#endif // TABLE_H
