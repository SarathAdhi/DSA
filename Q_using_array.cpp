#include<iostream>
using namespace std;

#define n 5
int a[n];
int front = -1, rear = -1;


bool isempty()
{
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}

void display()
{
    if(isempty())
        cout<<"Q is empty..";
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout<<a[i]<<" ";
        }
        
    }
}

void enqueue(int val)
{
    if(rear == n-1)
        cout<<"Q is full..";
    else
    {
        if(front == -1)
            front = 0;
        
        rear++;
        a[rear] = val;
        display();
    }
}

void dequeue()
{
    if(isempty())
    {
        cout<<"Q is empty..";
    }
    else
    {
        if(front == rear)
            front = rear = -1;
        else{
            front++;
        }
        display();
    }
}

void showfront()
{
    if (isempty())
        cout<<"Q is full..";
    else{
        cout<<a[front]<<endl;
    }
    
}


int main()
{
    int choice, val;
    while(choice != 4)
    {
        cout<<"\n\n1.Insertion\n2.Deletion\n3.Show top\n4.Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the Value to be Inserted: ";
                cin>>val;
                enqueue(val);
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                showfront();
                break;

            case 4:
                cout<<"Exit";
                break;

            default:
                cout<<"Wrong Choice..";
            
        }
    }
}