#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
Node *top = NULL;

void display(Node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<"->";
        p = p->link;
    }
}

void s_push(int a)
{
    Node *ptr = new Node();
    ptr->data = a;
    ptr->link = top;
    top = ptr;
    display(top);
}

void pop()
{
    if(top == NULL)
    {
        cout<<"Stack is Empty..";
    }
    else
    {
        Node *ptr = top;
        top = top->link;
        free(ptr);
        display(top);
    }
}

int main()
{
    int a, choice;
    while(choice != 3)
    {
        cout<<"\n\n1.Insertion\n2.Deletion\n3.Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the element to be pushed: ";
                cin>>a;
                s_push(a);
                break;
            
            case 2:
                pop();
                break;

            case 3:
                cout<<"Exit..";
                break;

            default:
                cout<<"Wrong choice..";
        }
    }
}