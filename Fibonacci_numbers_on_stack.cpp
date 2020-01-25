/*  Fibonacci numbers on stack.
    The number of Fibonacci indexes will be push on the stack structure. v4*/

#include <iostream>
#include <limits>

using namespace std;

int a = 1, b = 1;                                   //First and second index of Fibonacci sequence assigned by value 1.

int temp;                                           //Variable temporary integer declatarion.

class Node
{
public:
                                                    //Attributes declaration in class Node.
    int data;                                       //Variable integer data in class Node.

    Node *next;                                     //Pointer will points to the next node.

    Node (int y)                                    //Constructor with variable y.
    {
        data = y;                                   //Variable data assigned by value y.

        next = NULL;                                //Pointer adress default assigned by NULL.
    }
};

class Stack
{
public:
                                                    //Attributes declaration in class Stack.
    Node *head;                                     //Pointer will points to Stack head.

    Stack()                                         //Constructor of class Stack.
    {
        head = NULL;                                //Pointer adress default assigned by NULL.
    }

    ~Stack()                                        //Destructor will delete all nodes after programm.
    {
        while (head != NULL)
        {
            Node *del = head;                       //Pointer assigned by head adress.

            head = head -> next;                    //Adress to the next node assigned as head.

            delete [] del;                          //Delete currently del adress.
        }
    }

    void Push (Node *n)                             //Add node on the stack.
    {
        n -> next = head;                           //Pointer of currently node assigned by previous head adress.

        head = n;                                   //Currently node adress is assign as head.
    }

    bool IsEmpty()                                  //Test if the stack is empty.
    {
        if (head == NULL)

            return true;

        else

            return false;
    }

    void Pop()                                      //Delete currently head node.
    {
        if (IsEmpty() == true)                      //Test if the stack is empty.
        {
            cout << "The stack is empty!" << endl;
        }

        else
        {
            Node *del = head;                       //Pointer assigned by head adress.

            cout << "I've been deleted head number " << del -> data << " from the stack.\n" << endl;

            head = head -> next;                    //Adress to the next node assigned as head.

            delete [] del;                          //Delete currently del adress.
        }
    }

    void Print()                                    //Print the stack data from head.
    {
        if (IsEmpty() == true)                      //Test if the stack is empty.
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            Node *ptr = head;

            while (ptr != NULL)
            {
                cout << ptr -> data << endl;

                ptr = ptr -> next;                  //Adress to the next node assigned as ptr.
            }
        }
    }
};

int main()
{
    int how;                                        //Number of Fibonacci indexes.

    Stack Fib_stack;                                //Create stack with name fib_stack.

    cout << "################ Fibonacci Numbers ################\n" << endl;
    
    cout << "Enter a natural number of indexes between 1 and 25: ";

    while (!(cin >> how))                           //If the user input is a string. Show cout.
    {
        cout << endl << "The input isnt' a natural number between 1 and 25!" << endl;

        cin.clear();                                //Clear error flag in user input.
        
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');    //Delete user error input.

        cout << "Please try again. Enter a natural number of indexes between 1 and 25: ";
    }

    if (how < 0 || how > 25)                        //If user input is less then 0 or greater then 25.
    {
        cout << endl << "The number need to be greater or equal to 1 and less or equal to 25!" << endl;

        system("PAUSE");                            //Hold console after programm.

        exit(0);                                    //Exit programm.
    }
    else if (how >= 1)                              //If user input is greater or equal to 1.
    {
        cout << endl << how << " Fibbonacci indexes are pushed on the stack." << endl << endl;

        Node* n0 = new Node(a);                     //Create first node and assign by value of variable integer a.

        Fib_stack.Push(n0);                         //Push node in stack.

        if (how >= 2)                               //If user input is greater or equal to 2.
        {
            Node* n1 = new Node(b);                 //Create second node and assign by value of variable integer b.

            Fib_stack.Push(n1);                     //Push node in stack.

            if (how >= 3)                           //If user input is greater or equal to 3.
            {
                for (int i = 2; i < how; i++)
                {
                    Node* n = new Node(a + b);      //New node with next Fibonacci index.

                    Fib_stack.Push(n);

                    temp = a;

                    a = (a + b);                    //Value of next Fibonacci index.

                    b = temp;
                }
            }
        }
    }

    Fib_stack.Pop();                                //Delete currently head node.

    Fib_stack.Print();                              //Print the stack data from head.

    system("PAUSE");                                //Hold console after programm.

    return 0;
}