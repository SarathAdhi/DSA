#include<iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i ;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";

        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
}