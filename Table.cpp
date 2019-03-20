#include <iostream>
#include "Table.h"

Table::Table()
{
    table = new int[0];
    size = 0;
}

void Table::push_front(int n)
{
    size++;
    int* temp = new int[size];
    temp[0] = n;
    for(int i = 0; i < size-1; i++)
        temp[i+1] = table[i];
    delete table;
    table = temp;
}

void Table::pop_front()
{
    if(size > 0)
    {
        size--;
        int* temp = new int[size];
        for(int i = 1; i < size+1; i++)
            temp[i-1] = table[i];
        delete table;
        table = temp;
    }
}

void Table::push_back(int n)
{
    size++;
    int* temp = new int[size];
    temp[size-1] = n;
    for(int i = 0; i < size-1; i++)
        temp[i] = table[i];
    delete table;
    table = temp;
}

void Table::pop_back()
{
    if(size > 0)
    {
        size--;
        int* temp = new int[size];
        for(int i = 0; i < size; i++)
            temp[i] = table[i];
        delete table;
        table = temp;
    }
}

int Table::get_size()
{
    return size;
}

void Table::push(int ind, int n)
{
    if(ind <= size && ind >= 0)
    {
        size++;
        int* temp = new int[size];
        for(int i = 0; i < ind; i++)
        {
            temp[i] = table[i];
        }
        temp[ind] = n;
        for(int i = ind+1; i < size; i++)
            temp[i] = table[i-1];
        delete table;
        table = temp;
    }
}

void Table::pop(int ind)
{
    if(ind < size && ind >= 0)
        size--;
    int* temp = new int[size];
    for(int i = 0; i < ind; i++)
        temp[i] = table[i];
    for(int i = ind; i < size; i++)
        temp[i] = table[i+1];
    delete table;
    table = temp;
}

bool Table::find(int k)
{
    bool isElem = false;
    for(int i =0; i < size; i++)
    {
        if(table[i] == k)
        {
            isElem = true;
            break;
        }
    }
    return isElem;
}

void Table::show()
{
    std::cout << "Tablica:\n";
    for(int i =0; i < size; i++)
        std::cout << table[i] << " ";
    std::cout << std::endl;
}

Table::~Table()
{
    delete [] table;
}

