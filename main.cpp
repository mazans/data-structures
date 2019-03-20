#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <unistd.h>
#include "List.h"
#include "Table.h"
#include "Heap.h"
#include "BST.h"

using namespace std;

//#define MAIN

#if defined(MAIN)
void list_operation(vector<int>, int);
void table_operation(vector<int>, int);
void heap_operation(vector<int>, int);
void bst_operation(vector<int>, int);

int main(int argc, char **argv)
{
	while(true)
	{
		system("clear");
		int choice;
		cout << "Wybierz strukture danych wybierajac odpowiedni numer:" << endl
			 << "1. Tablica" << endl
			 << "2. Lista" << endl
			 << "3. Kopiec" << endl
             << "4. Drzewo BST" << endl << "0. Wyjscie" << endl;
		cin >> choice;
		
		if(choice == 0)
			return 0;
		
		string file_name;
		cout << "Podaj nazwe pliku z ktorego maja zostac pobrane dane: ";
		cin >> file_name;
		ifstream fin(file_name.c_str());
		
		vector<int> temp;
		int size;
		
		if(fin.is_open())
		{
			fin >> size;
			if(fin.fail())
			{
				cout << "Blad odczytu rozmiaru struktury!" << endl;;
				cin.get();
				cin.get();
				continue;
			}
			else
			{
				int val;
				for(int i = 0; i < size; i++)
				{
					fin >> val;
					if(fin.fail())
					{
						cout << "Blad w trakcie odczytu danych ze struktury!";
						cin.get();
						cin.get();
						fin.close();
						break;
					}
					else
					{
						temp.push_back(val);
					}
				}
				fin.close();
			}
		}
		else
		{
			cout << "Blad w trakcie otwierania pliku!" << endl;
			cin.get();
			cin.get();
			continue;
		}
		
		if(choice == 1)
		{
			system("clear");
			table_operation(temp, size);
		}
		
		else if(choice == 2)
		{
			system("clear");
			list_operation(temp, size);
		}
		
		else if(choice == 3)
		{
			system("clear");
			heap_operation(temp, size);
		}
        else if(choice == 4)
        {
            system("clear");
            bst_operation(temp, size);
        }
		else
		{
			cout << "Podano zla opcje!";
			cin.get();
			cin.get();
		}
	}
}

void bst_operation(vector<int> temp, int size)
{
    BST bst;
    int choice;
    int val;
    for(int i = 0; i < size; i++)
    {
        bst.push(temp[i]);
    }
    cout << "Wybierz opcje:" << endl
         << "1. Dodaj element" << endl
         << "2. Znajdz element" << endl
		 << "3. Rownowazenie drzewa" << endl
         << "0. Zakoncz operowanie na tej strukturze" << endl;
    while(true)
    {
        cout  << "Drzewo BST" << endl;
        bst.show();
        cout << "Rozmiar: " << bst.get_size() << endl;
        cout << "Podaj opcje: ";
        cin >> choice;
        if(choice == 1)
        {
            cout << "Podaj wartość: ";
            cin >> val;
            bst.push(val);
        }
        else if(choice == 2)
        {
            cout << "Podaj element do znalezienia: ";
            cin >> val;
            Node * temp = bst.find(val);
            if(temp)
            {
                cout << "Podana wartosc znajduje sie na liscie" << endl;
                cout << "Co chcesz zrobic z tym elementem?" << endl;
                cout << "1. Usunac" << endl;
				cout << "2. Wykonac rotacje w lewo" << endl;
				cout << "3. Wykonac rotacje w prawo" << endl;
                cout << "0. Nic" << endl;
                int inner_choice;
                cin >> inner_choice;
                if(inner_choice == 1)
                    bst.pop(temp);
				else if(inner_choice == 2)
					bst.rotate_left(temp);
				else if(inner_choice == 3)
					bst.rotate_right(temp);
            }
            else
            {
                cout << "Nie znaleziono zadanej wartosci" << endl;
            }
        }
		else if(choice == 3)
			bst.balance_DSW();
        else if(choice == 0)
        {
            return;
        }
        else
        {
            cout << "Podano nieprawidlowa opcje" << endl;
        }
    }
}

void heap_operation(vector<int> temp, int size)
{
	Heap heap;
	int choice;
	int val;
	for(int i = 0; i < size; i++)
	{
		heap.push(temp[i]);
	}
	cout << "Wybierz opcje:" << endl
		 << "1. Dodaj element" << endl
		 << "2. Usun element" << endl
		 << "3. Znajdz element" << endl
		 << "0. Zakoncz operowanie na tej strukturze" << endl;
	while(true)
	{
		cout  << "Kopiec" << endl;
		heap.show();
		cout << "Rozmiar: " << heap.get_size() << endl;
		cout << "Podaj opcje: ";
		cin >> choice;
		if(choice == 1)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			heap.push(val);
		}
		else if(choice == 2)
		{
			heap.pop();
		}
		else if(choice == 3)
		{
			cout << "Podaj element do znalezienia: ";
			cin >> val;
			bool is_found = heap.find(val);
			if(is_found)
			{
				cout << "Podana wartosc znajduje sie na liscie" << endl;
			}
			else
			{
				cout << "Nie znaleziono zadanej wartosci" << endl;
			}
		}
		else if(choice == 0)
		{
			return;
		}
		else
		{
			cout << "Podano nieprawidlowa opcje" << endl;
		}
	}
}

void table_operation(vector<int> vec, int size)
{
	Table table;
	int choice;
	int val;
	int ind;
	for(int i = 0; i < size; i++)
	{
		table.push_back(vec[i]);
	}
	cout << "Wybierz opcje:" << endl
		 << "1. Dodaj do przodu" << endl
		 << "2. Usun z przodu" << endl
		 << "3. Dodaj z tylu" << endl
		 << "4. Usun z tylu" << endl
		 << "5. Dodaj na wybranej pozycji" << endl
		 << "6. Usun z wybranej pozycji" << endl
		 << "7. Znajdz element" <<endl
		 << "0. Zakoncz operowanie na tej strukturze" << endl;
	while(true)
	{
		table.show();
		cout << "Rozmiar: " << table.get_size() << endl;
		cout << "Podaj opcje: ";
		cin >> choice;
		if(choice == 1)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			table.push_front(val);
		}
		else if(choice == 2)
		{
			table.pop_front();
		}
		else if(choice == 3)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			table.push_back(val);
		}
		else if(choice == 4)
		{
			table.pop_back();
		}
		else if(choice == 5)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			cout << "Podaj indeks: ";
			cin >> ind;
			table.push(ind, val);
		}
		else if(choice == 6)
		{
			cout << "Podaj indeks: ";
			cin >> ind;
			table.pop(ind);
		}
		else if(choice == 7)
		{
			cout << "Podaj element do znalezienia: ";
			cin >> val;
			bool is_found = table.find(val);
			if(is_found)
			{
				cout << "Podana wartosc znajduje sie na liscie" << endl;
			}
			else
			{
				cout << "Nie znaleziono zadanej wartosci" << endl;
			}
		}
		else if(choice == 0)
		{
			return;
		}
		else
		{
			cout << "Podano nieprawidlowa opcje" << endl;
		}
	}
}

void list_operation(vector<int> vec, int size)
{
	List list;
	int choice;
	int val;
	int ind;
	for(int i = 0; i < size; i++)
	{
		list.push_back(vec[i]);
	}
	cout << "Wybierz opcje:" << endl
		 << "1. Dodaj do przodu" << endl
		 << "2. Usun z przodu" << endl
		 << "3. Dodaj z tylu" << endl
		 << "4. Usun z tylu" << endl
		 << "5. Dodaj na wybranej pozycji" << endl
		 << "6. Usun z wybranej pozycji" << endl
		 << "7. Znajdz element" <<endl
		 << "0. Zakoncz operowanie na tej strukturze" << endl;
	while(true)
	{
		list.show();
		cout << "Rozmiar: " << list.get_size() << endl;
		cout << "Podaj opcje: ";
		cin >> choice;
		if(choice == 1)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			list.push_front(val);
		}
		else if(choice == 2)
		{
			list.pop_front();
		}
		else if(choice == 3)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			list.push_back(val);
		}
		else if(choice == 4)
		{
			list.pop_back();
		}
		else if(choice == 5)
		{
			cout << "Podaj wartość: ";
			cin >> val;
			cout << "Podaj indeks: ";
			cin >> ind;
			list.push(ind, val);
		}
		else if(choice == 6)
		{
			cout << "Podaj indeks: ";
			cin >> ind;
			list.pop(ind);
		}
		else if(choice == 7)
		{
			cout << "Podaj element do znalezienia: ";
			cin >> val;
			bool is_found = list.find(val);
			if(is_found)
			{
				cout << "Podana wartosc znajduje sie na liscie" << endl;
			}
			else
			{
				cout << "Nie znaleziono zadanej wartosci" << endl;
			}
		}
		else if(choice == 0)
		{
			return;
		}
		else
		{
			cout << "Podano nieprawidlowa opcje" << endl;
		}
	}
}




#else

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);

    int length_tab[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000};
    int tab_size  = 9;
    int repeat_number = 100;

    int choice ;
    while(true) {
        cout << "Podaj strukture do wykonania pomiaru czasu:" << endl;
        cout << "1. Tablica" << endl;
        cout << "2. Lista" << endl;
        cout << "3. Kopiec" << endl;
        cout << "4. Drzewo BST" << endl;
        cout << "0. Wyjdz" << endl;
        cin >> choice;
        if(choice == 0)
        {
            return 0;
        }
        else if(choice == 1)
        {
            long long sum_push, sum_pop, sum_find, sum_push_back, sum_pop_back, sum_push_front, sum_pop_front;
            chrono::time_point<chrono::high_resolution_clock> start, stop;

            cout << "Tablica:" << endl;
            for(int i = 0; i < tab_size; i++)
            {
                cout << "Pomiar wykonywania czasu dla talbicy o rozmiarze " << length_tab[i] << endl;

                sum_push = sum_pop = sum_find = sum_pop_back = sum_push_back = sum_pop_front = sum_push_front = 0;
                for(int k = 0; k < repeat_number; k++)
                {
                    Table table;
                    for (int j = 0; j < length_tab[i]; j++)
                    {
                        table.push_back(dist(gen));
                    }

                    typedef chrono::high_resolution_clock Clock;
                    int n = dist(gen);
                    int ind = length_tab[i]/2;

                    start = Clock::now();
                    table.push_front(n);
                    stop = Clock::now();
                    table.pop_front();
                    sum_push_front += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();

                    start = Clock::now();
                    table.pop_front();
                    stop = Clock::now();
                    table.push_front(n);
                    sum_pop_front += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();

                    start = Clock::now();
                    table.push_back(n);
                    stop = Clock::now();
                    table.pop_back();
                    sum_push_back += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();

                    start = Clock::now();
                    table.pop_back();
                    stop = Clock::now();
                    table.push_back(n);
                    sum_pop_back += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();

                    start = Clock::now();
                    table.push(ind, n);
                    stop = Clock::now();
                    table.pop(ind);
                    sum_push += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();

                    start = Clock::now();
                    table.pop(ind);
                    stop = Clock::now();
                    table.push(ind, n);
                    sum_pop += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();

                    start = Clock::now();
                    table.find(1000001);
                    stop = Clock::now();
                    sum_find += chrono::duration_cast<chrono::nanoseconds>(stop-start).count();
                }
                cout << "Sredni czas wstawiania elementu na początek: " <<  sum_push_front/100 << endl;
                cout << "Sredni czas usuwania elementu z początku: " << sum_pop_front/100 << endl;
                cout << "Sredni czas wstawiania elementu na koniec: " << sum_push_back/100 << endl;
                cout << "Sredni czas usuwania elementu z konca: " << sum_pop_back/100 << endl;
                cout << "Sredni czas wstawiania elementu na dana pozycje: " << sum_push/100 << endl;
                cout << "Sredni czas usuwania elementu z danej pozycji: " << sum_pop/100 << endl;
                cout << "Sredni czas wyszukiwania elementu: " << sum_find/100 << endl;
            }
        }
        else if(choice == 2)
        {
            long long sum_push, sum_pop, sum_find, sum_push_back, sum_pop_back, sum_push_front, sum_pop_front;
            chrono::time_point<chrono::high_resolution_clock> start, stop;

            cout << "Lista:" << endl;
            for (int i = 0; i < tab_size; i++) {
                cout << "Pomiar wykonywania czasu dla listy o rozmiarze " << length_tab[i] << endl;
                sum_push = sum_pop = sum_find = sum_pop_back = sum_push_back = sum_pop_front = sum_push_front = 0;
                for (int k = 0; k < repeat_number; k++)
                {
                    List list;
                    for (int j = 0; j < length_tab[i]; j++)
                    {
                        list.push_back(dist(gen));
                    }

                    typedef chrono::high_resolution_clock Clock;
                    int n = dist(gen);
                    int ind = length_tab[i] / 2;

                    start = Clock::now();
                    list.push_front(n);
                    stop = Clock::now();
                    list.pop_front();
                    sum_push_front += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    list.pop_front();
                    stop = Clock::now();
                    list.push_front(n);
                    sum_pop_front += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    list.push_back(n);
                    stop = Clock::now();
                    list.pop_back();
                    sum_push_back += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    list.pop_back();
                    stop = Clock::now();
                    list.push_back(n);
                    sum_pop_back += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    list.push(ind, n);
                    stop = Clock::now();
                    list.pop(ind);
                    sum_push += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    list.pop(ind);
                    stop = Clock::now();
                    list.push(ind, n);
                    sum_pop += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    list.find(1000001);
                    stop = Clock::now();
                    sum_find += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
                }
                cout << "Sredni czas wstawiania elementu na początek: " << sum_push_front / 100 << endl;
                cout << "Sredni czas usuwania elementu z początku: " << sum_pop_front / 100 << endl;
                cout << "Sredni czas wstawiania elementu na koniec: " << sum_push_back / 100 << endl;
                cout << "Sredni czas usuwania elementu z konca: " << sum_pop_back / 100 << endl;
                cout << "Sredni czas wstawiania elementu na dana pozycje: " << sum_push / 100 << endl;
                cout << "Sredni czas usuwania elementu z danej pozycji: " << sum_pop / 100 << endl;
                cout << "Sredni czas wyszukiwania elementu: " << sum_find / 100 << endl;
            }
        }
        else if(choice == 3)
        {
            long long sum_push, sum_pop, sum_find;
            chrono::time_point<chrono::high_resolution_clock> start, stop;

            cout << "Kopiec:" << endl;
            for (int i = 0; i < tab_size; i++) {
                cout << "Pomiar wykonywania czasu dla kopca o rozmiarze " << length_tab[i] << endl;

                sum_push = sum_pop = sum_find = 0;
                for (int k = 0; k < repeat_number; k++)
                {
                    Heap heap;
                    for (int j = 0; j < length_tab[i]; j++)
                    {
                        heap.push(dist(gen));
                    }

                    typedef chrono::high_resolution_clock Clock;
                    int n = dist(gen);

                    start = Clock::now();
                    heap.push(1000001);
                    stop = Clock::now();
                    heap.pop();
                    sum_push += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    heap.pop();
                    stop = Clock::now();
                    heap.push(n);
                    sum_pop += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    heap.find(1000001);
                    stop = Clock::now();
                    sum_find += chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
                }
                cout << "Sredni czas wstawiania elementu: " << sum_push / 100 << endl;
                cout << "Sredni czas usuwania elementu: " << sum_pop / 100 << endl;
                cout << "Sredni czas wyszukiwania elementu: " << sum_find / 100 << endl;
            }
        }
        else if(choice == 4)
        {
            long long sum_push, sum_pop, sum_find, sum_rotate_l, sum_rotate_r, sum_balance;
            chrono::time_point<chrono::high_resolution_clock> start, stop;

            cout << "Drzewo BST:" << endl;
            for (int i = 0; i < tab_size; i++) {
                cout << "Pomiar wykonywania czasu dla kopca o rozmiarze " << length_tab[i] << endl;

                sum_push = sum_pop = sum_find = sum_rotate_l = sum_rotate_r = sum_balance = 0;
                for (int k = 0; k < repeat_number; k++)
                {
                    BST bst;
                    for (int j = 0; j < length_tab[i]; j++)
                    {
                        bst.push(dist(gen));
                    }

                    typedef chrono::high_resolution_clock Clock;
                    int n = dist(gen);

                    start = Clock::now();
                    bst.balance_DSW();
                    stop = Clock::now();
                    sum_balance +=  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    start = Clock::now();
                    bst.find(1000001);
                    stop = Clock::now();
                    sum_find +=  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    Node *node = bst.get_root();

                    start = Clock::now();
                    bst.rotate_left(node);
                    stop = Clock::now();
                    sum_rotate_l +=  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    node = bst.get_root();

                    start = Clock::now();
                    bst.rotate_right(node);
                    stop = Clock::now();
                    sum_rotate_r +=  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    node = bst.get_root();

                    start = Clock::now();
                    bst.pop(node);
                    stop = Clock::now();
                    sum_pop +=  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                    bst.push(n);
                    n = dist(gen);
                    bst.balance_DSW();

                    start = Clock::now();
                    bst.push(n);
                    stop = Clock::now();
                    sum_push +=  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

                }
                cout << "Sredni czas wstawiania elementu: " << sum_push / 100 << endl;
                cout << "Sredni czas usuwania elementu: " << sum_pop / 100 << endl;
                cout << "Sredni czas wyszukiwania elementu: " << sum_find / 100 << endl;
                cout << "Sredni czas rotacji w lewo:" << sum_rotate_l / 100 << endl;
                cout << "Sredni czas rotacji w prawo:" << sum_rotate_r / 100 << endl;
                cout << "Sredni czas balansowania drzewa:" << sum_balance / 100 << endl;
            }
        }
        else
        {
            cout << "Podano zla opcje!";
            cin.get();
            cin.get();
        }
        system("clear");
    }
}
#endif