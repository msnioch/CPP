//The number of Fibonacci indexes will be push on stack and print.

#include <iostream>
using namespace std;

int a = 1, b = 1, temp;

class node
{
public:
    int data;

    node* next;

    node(int y)
    {
        data = y;

        next = NULL;
    }
};

class stack
{
public:
    node* head;

    stack()
    {
        head = NULL;
    }

    ~stack()
    {
        while (head != NULL)
        {
            node* del = head;

            head = head->next;

            delete[] del;
        }
    }

    void push(node* n)
    {
        n->next = head;

        head = n;
    }

    bool isEmpty()
    {
        if (head == NULL)

            return true;

        else

            return false;
    }

    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "The stack is empty!" << endl;
        }

        else
        {
            node* del = head;

            head = head->next;

            delete[] del;

            if (isEmpty() == true)
            {
                cout << "The stack is empty!" << endl;
            }
        }
    }

    void print()
    {
        node* ptr = head;

        while (ptr != NULL)
        {
            cout << ptr->data << endl;

            ptr = ptr->next;
        }
    }
};

int main()
{
    int how;

    cout << "$$$$$ Fibonacci Numbers. $$$$$\nEnter a whole number of indexes: ";

    cin >> how;

    cout << "\nYou see under " << how << " Fibonacci indexes are pushed on the stack.\n" << endl;

    stack S;

    node* n0 = new node(a);

    S.push(n0);

    node* n1 = new node(b);

    S.push(n1);

    for (int i = 2; i < how; i++)
    {
        node* n = new node(a + b);      //New node with next Fibonacci index.

        S.push(n);

        temp = a;

        a = (a + b);        //Value of next Fibonacci index.

        b = temp;
    }

    S.pop();

    S.print();

    return 0;
}