#include<iostream>
using namespace std;


int main()
{
    int i,j,k,key;
    int n;
    cout<<"Enter the size => ";
    cin>>n;
    int a[n];
    cout<<"Enter the array elements => ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<n;i++)
    {
        key = a[i];
        j=i-1;
        while(a[j]>key && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = key;
    }

    cout<<"Sorted Array is => ";
    for(j=1;j<n;j++)
    {
        cout<<" === "<<a[j]<<" === ";
    }

    return 0;
}
