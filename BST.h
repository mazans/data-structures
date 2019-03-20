#ifndef SDIZO_BST_H
#define SDIZO_BST_H
#include<string>

using std::string;

struct Node //struktura bedaca wezlem drzewa
{
    int data; //faktycznie przechowywane dae
    Node *up; //wskaznik na ojca
    Node *right; //wskaznik na lewego syna
    Node *left; //wskaznik na prawego syna
};


class BST //Klasa implementujaca drzewo BST
{
private:
    Node *root; //wskaznik na korzen drzewa BST
    int size; //rozmiar drzewa

    Node * find_successor(Node * n); //metoda pomocnicza, sluzy do znajdowania nastepnika w drzewie BST
    void remove_tree(Node *); //metoda pomocnicza, wykorzystywana w destruktorze
    void show_helper(Node *n, int depth, string branch); //metoda pomocnicza, wykorzystywana przy wyswietlaniu drzewa
public:
    BST();
    ~BST();

    int get_size(); //zwraca rozmiar drzewa

    void push(int n); //wstawia do drzewa element o wartosci n
    void pop(Node * n); //usuwa z drzewa element o wartosci n
    Node* find(int n); //sprawdza czy w drzewie znajduje sie podany element n
    void rotate_left(Node *n); //rotacja podanego wezla w lewo
    void rotate_right(Node *n); //rotacja podanego wezla w prawo
    void balance_DSW(); //rownowazenie drzewa algorrytmem DSW
    Node * get_root(); //zwraca korzen drzewa, przydatne przy badaniu zlozonosci obliczeniowej


    void show(); //wyswietla zawartosc drzewa
};


#endif //SDIZO_BST_H
