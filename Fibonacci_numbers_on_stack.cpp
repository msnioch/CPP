/*  Fibonacci numbers on stack.
    The number of Fibonacci indexes will be push on the stack structure. v4*/

#include <iostream>
#include <limits>

using namespace std;

int pre_previous_index = 1, previous_index = 1;                                             //First and second index of Fibonacci sequence assigned by value 1.

int temp;                                                                                   //Variable temporary integer declatarion.

class Node
{
public:
                                                                                            //Attributes declaration in class Node.
    int data;                                                                               //Variable integer data in class Node.

    Node *next;                                                                             //Pointer points to the next node.

    Node (int default_data)                                                                 //Constructor.
    {
        data = default_data;                                                                //Variable data assigned by value default_data.

        next = NULL;                                                                        //Pointer adress default assigned by NULL.
    }
};

class Stack
{
public:
                                                                                            //Attributes declaration in class Stack.
    Node *head;                                                                             //Pointer points to Stack head.

    Stack()                                                                                 //Constructor of class Stack.
    {
        head = NULL;                                                                        //Pointer adress default assigned by NULL.
    }

    ~Stack()                                                                                //Destructor delete all nodes after programm.
    {
        while (head != NULL)
        {
            Node *del = head;                                                               //Pointer assigned by head adress.

            head = head -> next;                                                            //Adress to the next node assigned as head.

            delete [] del;                                                                  //Delete currently del adress.
        }
    }

    void Push (Node *new_adress)                                                            //Add node on the stack.
    {
        new_adress -> next = head;                                                          //Pointer of currently node assigned by previous head adress.

        head = new_adress;                                                                  //Currently node adress is assign as head.
    }

    bool IsEmpty()                                                                          //Test if the stack is empty.
    {
        if (head == NULL)

            return true;

        else

            return false;
    }

    void Pop()                                                                               //Delete currently head node.
    {
        if (IsEmpty() == true)                                                               //Test if the stack is empty.
        {
            cout << "The stack is empty!" << endl;
        }

        else
        {
            Node *del = head;                                                                 //Pointer assigned by head adress.

            cout << "I've been deleted head number " << del -> data << " from the stack.\n" << endl;

            head = head -> next;                                                              //Adress to the next node assigned as head.

            delete [] del;                                                                    //Delete currently del adress.
        }
    }

    void Print()                                                                              //Print the stack data from head.
    {
        if (IsEmpty() == true)                                                                //Test if the stack is empty.
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            Node *ptr = head;

            while (ptr != NULL)
            {
                cout << ptr -> data << endl;

                ptr = ptr -> next;                                                              //Adress to the next node assigned as ptr.
            }
        }
    }
};

int main()
{
    int how;                                                                                    //Number of Fibonacci indexes.

    Stack Fib_stack;                                                                            //Create stack with name fib_stack.

    cout << "################ Fibonacci Numbers ################\n" << endl;
    
    cout << "Enter a natural number of indexes between 1 and 25: ";

    while (!(cin >> how))                                                                       //If the user input is a string. Show cout.
    {
        cout << endl << "The input isnt' a natural number between 1 and 25!" << endl;

        cin.clear();                                                                            //Clear error flag in user input.
        
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');                                //Delete user error input.

        cout << "Please try again. Enter a natural number of indexes between 1 and 25: ";
    }

    if (how < 0 || how > 25)                                                                    //If user input is less then 0 or greater then 25.
    {
        cout << endl << "The number need to be greater or equal to 1 and less or equal to 25!" << endl;

        system("PAUSE");                                                                        //Hold console after programm.

        exit(0);                                                                                //Exit programm.
    }
    else if (how >= 1)                                                                          //If user input is greater or equal to 1.
    {
        cout << endl << how << " Fibbonacci indexes are pushed on the stack." << endl << endl;

        Node *zero_node = new Node (pre_previous_index);                                        //Create first node and assign by value of variable integer pre_previous_index.

        Fib_stack.Push(zero_node);                                                              //Push node in stack.

        if (how >= 2)                                                                           //If user input is greater or equal to 2.
        {
            Node *first_node = new Node (previous_index);                                       //Create second node and assign by value of variable integer previous_index.

            Fib_stack.Push(first_node);                                                         //Push node in stack.

            if (how >= 3)                                                                       //If user input is greater or equal to 3.
            {
                for (int current_index = 2; current_index < how; current_index++)
                {
                    Node *current_node = new Node (pre_previous_index + previous_index);        //New node with current index.

                    Fib_stack.Push (current_node);

                    temp = pre_previous_index;                                                  //Temporary variable temp assigned by pre_previous_index.

                    pre_previous_index = (pre_previous_index + previous_index);                 //Value of current index.

                    previous_index = temp;                                                      //previous_index variable assigned by pre_previous_index.
                }
            }
        }
    }

    Fib_stack.Pop();                                                                             //Delete currently head node.

    Fib_stack.Print();                                                                           //Print the stack data from head.

    system("PAUSE");                                                                             //Hold console after programm.

    return 0;
}