#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap()
{
    table = new int[0];
    size = 0;
}

void Heap::push(int elem)
{
    size++;
    int *temp = new int[size];
    for(int i = 0; i < size - 1; i++)
        temp[i] = table[i];
    delete [] table;
    table = temp;
    int son = size -1;
    int par = (son-1)/2;
    while(son > 0 && elem > table[par])
    {
        table[son] = table[par];
        son = par;
        par = (son-1)/2;
    }
    table[son] = elem;
}

void Heap::pop()
{
    if(size)
    {
        int elem = table[size-1];
        size--;
        int *temp = new int[size];
        for(int i = 0; i < size; i++)
            temp[i] = table[i];
        delete [] table;
        table = temp;
        int par = 0;
        int son = 1;
        if(son+1 < size && table[son+1] > table[son])
            son++;
        while(son < size && elem < table[son])
        {
            table[par] = table[son];
            par = son;
            son = 2*par+1;
            if(son+1 < size && table[son+1] > table[son])
                son++;
        }
        table[par] = elem;
    }
}

int Heap::get_size()
{
    return size;
}

void Heap::show()
{
    show_helper(0, 0, "");
}

void Heap::show_helper(int ind, int depth, string branch)
{
    if(ind < size)
    {
        show_helper(2*ind+2, depth+1, "/--");

        for(int i = 0; i < depth-1; i++)
            cout << "   ";
        cout <<  branch << table[ind] << endl;

        show_helper(2*ind+1, depth+1, "\\--");
    }
}

bool Heap::find(int n)
{
    bool isElem = false;
    for(int i =0; i < size; i++)
    {
        if(table[i] == n)
        {
            isElem = true;
            break;
        }
    }
    return isElem;
}

Heap::~Heap()
{
    delete [] table;
}

