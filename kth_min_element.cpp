#include<bits/stdc++.h>
using namespace std;
void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int partition(int a[], int low,int high)
{
    int pivot = a[high];
    int pos=low;
    for(int i=low;i<=high;i++)
    {
        if(a[i]<pivot) {
            int temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
            pos++;
        }
    }
    int temp = a[pos];
    a[pos]=pivot;
    a[high]=temp;

    print(a,9);
    return pos;

}
int select(int a[],int n,int k)
{
    int low=0;
    int high=n;
    int pos;
    while(low<=high) {
        pos = partition(a,low,high);
        if(pos == k)
            break;
        else if(pos<k)
            low=pos+1;
        else
            high = pos-1;
    }
    return pos;
}
int main()
{
    int a[] = {65,70,75,80,85,60,55,50,45};
    int n = sizeof (a)/sizeof (a[0]);
    int k=5;
    cout<<a[select(a,n-1,k-1)];
}