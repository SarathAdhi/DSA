#include<iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    int pos, temp;
    for(int i=0;i<n-1;i++)
    {
        pos = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;

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
    selectionsort(arr,n);
}