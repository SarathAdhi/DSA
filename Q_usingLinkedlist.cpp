#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *front = NULL;
Node *rear = NULL;

bool isempty()
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void display()
{
    if (isempty())
        cout << "\nQ is empty..";

    else
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr=ptr->link;
        }
    }
}

void enqueue(int val)
{
    Node *ptr = new Node();
    ptr->data = val;
    ptr->link = NULL;

    if (front == NULL) //If inserting the first element/node
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
    display();
}

void dequeue()
{
    if (isempty())
        cout << "\nQ is empty..";

    else
    {
        if (front == rear)
        {
            free(front);
            front = NULL;
            rear = NULL;
        }
        else
        {
            Node *ptr = front;
            front = front->link;
            free(ptr);
        }
        display();
    }
}

void showfront()
{
    if (isempty())
        cout << "\nQ is empty..";

    else
    {
        cout << "\nThe front element is: " << front->data;
    }
}

int main()
{
    int choice, val;
    int flag = 1;
    
    while (flag == 1)
    {
        cout << "\n\n1.Insertion\n2.Deletion\n3.Show Front\n4.Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "\nEnter the value to be inserted: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                showfront();
                break;

            case 4:
                flag = 0;
                break;

            default:
                cout << "Wrong Choice..";
                break;
        }
    }
}