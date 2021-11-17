#include<iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int num)
{
    while(left<=right)
    {
        int mid = (right + left)/2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] < num)
        {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int binarysearch_recursion(int arr[], int left, int right, int num)
{
    if(left<=right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] < num)
        {
            return binarysearch_recursion(arr, mid+1, right, num);
        }
        else{
            return binarysearch_recursion(arr, left, mid-1, num);
        }
    }
    return -1;
}

int main()
{
    int n, num, res;
    cout<<"Enter no.of Element: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int choice;
    while(choice != 3)
    {
        cout<<"\n\nEnter the Element to be Searched: ";
        cin>>num;

        cout<<"\n\n1. Normal binary search\n2. Recursion binary search\n3. Exit\nEnter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            res = binarysearch(arr, 0, n-1, num);
            if(res == -1)
                cout<<"\nElement not found..";
            else
                cout<<"\nElement found at Position: "<<res+1;
            break;

        case 2:
            res = binarysearch_recursion(arr, 0, n-1, num);
            if(res == -1)
                cout<<"\nElement not found..";
            else
                cout<<"\nElement found at Position: "<<res+1;
            break;
        
        default:
            break;
        }
    }

    
}