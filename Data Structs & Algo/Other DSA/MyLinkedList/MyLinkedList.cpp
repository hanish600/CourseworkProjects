#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
} 
*first = NULL;

void create(int A[], int n)
{
    struct Node* t, * last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;
    for (int i = 1; i < n; ++i)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}


void Display()
{
    Node *Iter = new Node;
    Iter = first;
    while (Iter)
    {
        cout << Iter->data<<" ";
        Iter = Iter->next;
    }
}

int SumOfNodes(struct Node* p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int NodeCount(struct Node* p)
{
    int count = 0;
    while (p)
    {
        ++count;
        p = p->next;
    }
    return count;
}

void MINMAX(struct Node* p,int *min,int *max)
{
    *max = *min = p->data;
    while (p)
    {
        if (*max < p->data)
        {
            *max = p->data;
        }
        else
        {
            *min = p->data;
        }
        p = p->next;
    }
}

bool Search(struct Node* p,int key)
{
    while (p)
    {
        if (p->data == key)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

Node* SearchSort(struct Node* p, int key)
{
    struct Node* q = nullptr;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return nullptr;
}

void Insert(int pos, int key)
{
    Node* t, * p;
    if (pos == 0)
    {
        t = new Node;
        t->data = key;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos-2 && p; ++i)
        {
            p = p->next;
        }
        t = new Node;
        t->data = key;
        t->next = p->next;
        p->next = t;
    }
}

void InsertEnd(int key)
{
    Node *Last = new Node;
    Last = first;
    int count = 1;
    while (count!=NodeCount(first))
    {
        ++count;
        Last = Last->next;
    }
    Node* t = new Node;
    t->data = key;
    t->next = Last->next;
    Last->next = t;

}

void SortedInsert(int key)
{
    struct Node* q = new Node;
    struct Node* p = new Node;
    p = first;
    struct Node* tmp = new Node;
    tmp->data = key;
    if (first == nullptr)
    {
        first = tmp;
        return;
    }
    while (p && p->data < key)
    {
        q = p;
        p = p->next;
    }
    if (p == first)
    {
        tmp->next = first;
        first = tmp;
    }
    else
    {
        tmp->next = q->next;
        q->next = tmp;
    }
}

int RemoveNode(int position = 0)
{
    Node* p = new Node;
    p = first;
    Node* q = new Node;
    q = nullptr;
    int tmp;
    if (position == 0)
    {
        first = p->next;
        tmp = p->data;
        delete p;
        return tmp;
    }
    for (int i = 0; i < position && p; ++i)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    tmp = p->data;
    delete p;
    return tmp;
}

int DeleteKey(int key)
{
    Node* p = new Node;
    Node* q = new Node;
    p = first;
    int tmp;
    if (p->data==key)
    {
        first = p->next;
        tmp = p->data;
        delete p;
        return tmp;
    }
    while (p->data != key)
    {
        q = p;
        p = p->next;
        if (p->data == key)
        {
            tmp = p->data;
            q->next = p->next;
            delete p;
            return tmp;
        }
    }
    return -1;
}

void CheckSorted()
{
    Node* p = new Node;
    Node* q = new Node;
    p = first;
    while (p)
    {
        q = p;
        p = p->next;
        if (p && q->data > p->data)
        {
            cout << "Not Sorted" << endl;
            return;
        }
    }
    cout << "Sorted" << endl;
    return;
}

void RemoveDuplication()
{
    Node* p = new Node;
    Node* q = new Node;
    p = first;
    q = first->next;
    while (q)
    {
        if (q && p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

void ReverseList()
{
    Node* p = new Node;
    Node* q = new Node;
    Node* r = new Node;
    p = first;
    q = r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    int A[] = { 3,5,7,10,15 };
    create(A, 5);
    //Display(first);
    //cout << SumOfNodes(first);
    //cout << NodeCount(first);
    //int max, min;
    //MINMAX(first,&min,&max);
    //cout << "Min:" << min << " Max:" << max;
    /*
    int data=Search(first, 16);
    if (data==true)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    } */
    /*
    SearchSort(first, 10);
    Insert(4, 23);
    Insert(0, 33);
    InsertEnd(61);
    InsertEnd(44); */
    /*
    SortedInsert(11);
    SortedInsert(8);
    SortedInsert(0);
    SortedInsert(8); */
    //RemoveNode();
    //RemoveNode(2);
    /*
    DeleteKey(3);
    DeleteKey(15);
    DeleteKey(7); */
    // CheckSorted();
    //RemoveDuplication();
    //ReverseList();
    Display();

    return 0;
}