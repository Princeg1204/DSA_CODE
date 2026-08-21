#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forLL(curr) for (Node *curr = head; curr; curr = curr->next)

struct Node
{
    // public:
    int data;
    struct Node *next;
    Node() { next = nullptr; }
    Node(int d) : data(d) { next = nullptr; }
};

class LinkedList
{
public:
    Node *head;
    LinkedList() { head = nullptr; }
    LinkedList(Node *h) : head(h) {}

    void insertNodeTail(int val);
    void deleteNode(int pos);
    void print();
    bool search(int target);
    int length();
};

void LinkedList::insertNodeTail(int val)
{
    if (!head)
    {
        head = new Node(val);
        return;
    }
    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = new Node(val);
    return;
}

