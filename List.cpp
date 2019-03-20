#include <iostream>
#include "List.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::push_front(int n)
{
    if(head)
    {
        Element *p = new Element;
        p->data = n;
        p->next = head;
        p->prev = nullptr;
        head->prev = p;
        head = p;
    }
    else
    {
        head = new Element;
        head->data = n;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }
    size++;
}

void List::pop_front()
{
    if(head)
    {
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Element *p = head->next;
            delete head;
            head = p;
            p->prev = nullptr;
        }
        size--;
    }
}

void List::push_back(int n)
{
    if(tail)
    {
        Element* p = new Element;
        p->data = n;
        p->next = nullptr;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
    else
    {
        tail = new Element;
        tail->data = n;
        tail->next = nullptr;
        tail->prev = nullptr;
        head = tail;
    }
    size++;
}

void List::pop_back()
{
    if(tail)
    {
        if(tail == head)
        {
            delete tail;
            tail = head = nullptr;
        }
        else
        {
            Element *p = tail->prev;
            delete tail;
            tail = p;
            tail->next = nullptr;
        }
        size--;
    }
}

int List::get_size()
{
    return size;
}

void List::push(int ind , int n)
{
    if(ind == 0)
    {
        push_front(n);
    }
    else if(ind == size)
    {
        push_back(n);
    }
    else if(size > ind && ind > 0)
    {
        Element *temp = head;
        int i = 0;
        Element *p = new Element;
        p->data = n;
        while(i < ind)
        {
            i++;
            temp = temp->next;
        }
        p->next = temp;
        p->prev = temp->prev;
        p->prev->next = p;
        temp->prev = p;
        size++;
    }
}

void List::pop(int ind)
{
    if(ind == 0)
    {
        pop_front();
    }
    if(ind == size - 1)
    {
        pop_back();
    }
    if(size - 1 > ind && ind > 0)
    {
        Element *p = head;
        int i = 0;
        while(i < ind)
        {
            i++;
            p = p->next;
        }
        p->next->prev = p->prev;
        p->prev->next = p->next;
        delete p;
        size--;
    }
}

bool List::find(int k)
{
    bool isElem = false;
    Element *p = head;
    while(p)
    {
        if(p->data == k)
        {
            isElem = true;
            break;
        }
        p = p->next;
    }
    return isElem;
}

void List::show()
{
    Element *p = head;
    std::cout << "Lista:\n";
    while(p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

List::~List()
{
    if(head)
    {
        Element *p = head;
        while(p)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }
}

