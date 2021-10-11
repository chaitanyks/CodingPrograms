#include<bits/stdc++.h>
using namespace std;
void insert(int a[] ,int data ,int n)
{
    a[n] = data;
    int item = a[n];
    int i = n;
    while(i>1&&a[i/2]<item)
    {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = data;
}

void adjust(int a[],int i,int n)
{
    int j=2*i;
    int item = a[i];
    while(j<=n)
    {
        if(j<n && a[j]<a[j+1])
            j=j+1;
        if(item>=a[j])
            break;
        a[j/2] = a[j];
        j= 2*j;
    }
    a[j/2] = item;
}

void removeMax(int a[],int n)
{
    int item = a[n];
    a[1] = a[n];
    adjust(a,1,n-1);
}

void heapSort(int a[],int n)
{
//    int sort[n];
    for(int i=1;i<=n;i++)
    {
        int temp = a[n-i+1];
        a[n-i+1] = a[1];
        a[1] = temp;
//        sort[n-i+1] = a[i];


        adjust(a,1,n-i);
    }

//    for(int j=1;j<=n;j++) {
//        cout<<sort[j]<<" ";
//    }
}
void heapify(int a[],int n)
{
    for(int i = n/2;i>=1;i--)
    {
        adjust(a,i,n);
    }
}
int main() {
    int n=10;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        insert(a,i*2, i);
    }
    cout<<"Original Heap : ------------------"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
//    removeMax(a,10);
//    n=n-1;
    heapSort(a,n);
    cout<<"Heap Sort : ------------------"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    heapify(a,n);

    cout<<"Heapify : ------------------"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
