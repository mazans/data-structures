#include "BST.h"
#include <iostream>
#include <cmath>

using namespace std;

BST::BST()
{
    root = nullptr;
    size = 0;
}

int BST::get_size()
{
    return size;
}

void BST::push(int n)
{
    Node * p = new Node;
    p -> data = n;
    p -> left = nullptr;
    p -> right = nullptr;
    if(root)
    {
        Node *temp = root;
        while(true)
        {
            if(n < temp->data)
            {
                if(temp->left)
                    temp = temp -> left;
                else
                {
                    temp -> left = p;
                    break;
                }
            }
            else
            {
                if(temp->right)
                    temp = temp->right;
                else
                {
                    temp -> right = p;
                    break;
                }
            }
        }
        p -> up = temp;
    }
    else
    {
        root = p;
        p -> up = nullptr;
    }
    size++;
}

void BST::pop(Node* n)
{
    if(!root)
        return;
    if(n->left && n->right)
    {
        Node* successor = find_successor(n);
        n->data = successor->data;
        pop(successor);
    }
    else
    {
        if(n->right)
        {
            n->right->up = n->up;
            if(!n->up)
                root = n->right;
            else if(n->up->left == n)
                n->up->left = n->right;
            else
                n->up->right = n->right;
        }
        else if(n->left)
        {
            n->left->up = n->up;
            if(!n->up)
                root = n->left;
            else if(n->up->left == n)
                n->up->left = n->left;
            else
                n->up->right = n->left;
        }
        else
        {
            if(!n->up)
                root = nullptr;
            else if(n->up->left == n)
                n->up->left = nullptr;
            else
                n->up->right = nullptr;
        }
        delete n;
        size--;
    }
}

Node * BST::find_successor(Node *n)
{
    if(n)
    {
        if(n->right)
        {
            n = n->right;
            while (n->left)
                n = n->left;
        }
        else
        {
            Node * father = n->up;
            while (father && n == father->right)
            {
                n = father;
                father = father->up;
            }
            n = father;
        }
    }
    return n;
}

Node* BST::find(int n)
{
    Node *temp = root;
    while(temp)
    {
        if(n == temp ->data)
            break;
        else if(n < temp->data)
            temp = temp -> left;
        else
            temp = temp -> right;
    }
    return temp;
}

void BST::show()
{
    show_helper(root, 0, "");
}

void BST::show_helper(Node * n, int depth, string branch )
{
    if(n)
    {
        show_helper(n->right, depth+1, "/--");

        for(int i = 0; i < depth-1; i++)
            cout << "   ";
        cout << branch << n->data << endl;

        show_helper(n->left, depth+1, "\\--");
    }
}

void BST::rotate_left(Node *n)
{
    Node *temp = n->right;
    if(temp)
    {
        n->right = temp->left;
        temp->left = n;
        if(n->right)
            n->right->up = n;

        temp->up = n->up;

        if(!n->up)
            root = temp;
        else if(n->up->left == n)
            n->up->left = temp;
        else
            n->up->right = temp;
        n->up = temp;
    }

}

void BST::rotate_right(Node *n)
{
    Node *temp = n->left;
    if(temp)
    {
        n->left = temp->right;
        temp->right = n;
        if(n->left)
            n->left->up = n;

        temp->up = n->up;

        if(!n->up)
            root = temp;
        else if(n->up->left == n)
            n->up->left = temp;
        else
            n->up->right = temp;
        n->up = temp;
    }
}

void BST::balance_DSW()
{
    Node *temp = root;
    while(temp)
    {
        while(temp->left)
        {
            rotate_right(temp);
            temp = temp->up;
        }
        temp = temp->right;
    }
    temp = root;
    int m = (int) pow(2,(int) log2(size + 1)) - 1;
    for(int i = 0; i < size - m; i++)
    {
        rotate_left(temp);
        temp = temp->up->right;
    }
    while(m > 1)
    {
        m = m/2;
        temp = root;
        for(int i = 0; i < m; i++)
        {
            rotate_left(temp);
            temp = temp->up->right;
        }
    }
}

void BST::remove_tree(Node * n)
{
    if(n)
    {
        remove_tree(n -> left);
        remove_tree(n -> right);
        delete n;
    }
}

Node * BST::get_root()
{
    return root;
}

BST::~BST()
{
    remove_tree(root);
}