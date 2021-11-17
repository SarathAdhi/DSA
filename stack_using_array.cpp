#include<iostream>
using namespace std;

#define n 5
int a[n];
int top = -1;

bool isempty()
{
    if(top == -1)
    {
        return true;
    }
    else
        return false;
}

void display()
{
    if(isempty())
    {
        cout<<"\nStack is empty..\n";
    }
    else
    {
        for(int i=0;i<=top;i++)
            cout<<a[i]<<" ";
    }
}

void push(int b)
{
    if(top == n-1)
    {
        cout<<"\nStack is full..\n";
    }
    else
    {
        top++;
        a[top] = b;
        display();
    }
    
}

void pop()
{
    if(isempty())
    {
        cout<<"\nStack is empty..\n";
    }
    else
    {
        top--;
        display();
    }
    
}

int main()
{
    int choice, b;

    while(choice != 3)
    {
        cout<<"\n\n1.Insertion\n2.Deletion\n3.Exit\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<"\nEnter the element to Push into Stack: ";
            cin>>b;
            push(b);
            break;
        
        case 2:
            pop();
            break;

        case 3:
            cout<<"Exit";
            break;

        default:
        cout<<"Wrong Choice..";
            break;
        }
    }
}