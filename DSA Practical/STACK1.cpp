#include <iostream>
using namespace std;
class Stack
{
private:
    int stack[5];
    int top;
    int size;

public:
    // Constructor
    Stack()
    {
        size = 5;
        top = -1;
    }

    // Push Operation
    void push(int value)
    {
        if(top == size - 1)
        {
            cout << "\nStack Overflow! Stack is Full.\n";
            return;
        }

        top++;
        stack[top] = value;

        cout << "\nElement Pushed Successfully.\n";
    }

    // Pop Operation
    void pop()
    {
        if(top == -1)
        {
            cout << "\nStack Underflow! Stack is Empty.\n";
            return;
        }

        cout << "\nDeleted Element : " << stack[top] << endl;
        top--;
    }

    // Display Stack
    void display()
    {
        if(top == -1)
        {
            cout << "\nStack is Empty.\n";
            return;
        }

        cout << "\nStack Elements : ";

        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    int choice, value;

    do
    {
        cout << "\n================STACK MENU===============\n";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter Element : ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "\nProgram Terminated Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
