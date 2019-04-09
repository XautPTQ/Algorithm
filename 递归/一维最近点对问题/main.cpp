#include <iostream>
#include<stdlib.h>
using namespace std;
#define maxint 1000
template<class Type>
void Swap(Type &a,Type &b)
{
    Type temp=a;
    a=b;
    b=temp;
}
template<class Type>
int Partition(Type A[],int p,int r)
{
    int temp=A[p];
    while(p<r)
    {
        while(p<r&&A[r]>temp)
            r--;
        if(p<r)
        {
            A[p]=A[r];
            p++;
        }
        while(p<r&&A[p]<temp)
            p++;
        if(p<r)
        {
            A[r]=A[p];
            r--;
        }
    }
    A[p]=temp;
    return p;
}
template<class Type>
int PartitionFour(Type A[],int p,int r,int k)
{
    int pos;
    for(int i=p;i<=r;i++)
    {
        if(A[i]==k)
        {
            pos=i;
            break;
        }
    }
    Swap(A[p],A[pos]);
    return Partition(A,p,r);
}
template<class Type>
int RandomPartition(Type A[],int p,int r)
{
    int i=rand()%(r-p+1)+p;
    Swap(A[p],A[i]);
    return Partition(A,p,r);
}
template<class Type>
void quickSort(Type A[],int p,int r)
{
    if(p<r)
    {
        int i=RandomPartition(A,p,r);
        quickSort(A,p,i-1);
        quickSort(A,i+1,r);
    }
}
template<class Type>
Type select(Type A[],int p,int r,int k)
{
    if(r-p<75){
        quickSort(A,p,r);
        return A[p+k-1];
    }
    for(int i=0;i<=(r-p-4)/5;i++)
    {
        Type x=select(A,p,p+(r-p-4)/5,(r-p-4)/10);
        int temp=PartitionFour(A,p,r,x);
        int j=temp-p+1;
        if(k<=j)
            return select(A,p,temp,k);
        else
            return select(A,temp+1,r,k-j);
    }
}
template<class Type>
Type Max(Type A[],int n)
{
    int Max=A[0];
    for(int i=1;i<n;i++)
        if(A[i]>Max)
            Max=A[i];
    return Max;
}
template<class Type>
Type Min(Type A[],int n)
{
    int Min=A[0];
    for(int i=1;i<n;i++)
        if(A[i]<Min)
            Min=A[i];
    return Min;
}
template<class Type>
Type Min(Type a,Type b,Type c)
{
    if(a<b&&a<c)
        return a;
    if(b<a&&b<c)
        return b;
    if(c<a&&c<b)
        return c;
}
template<class Type>
Type Cpairs(Type A[],int n)
{
   Type dmin=maxint;
   Type d;
   if(n<2)
   {
       d=maxint;
       return d;
   }
   Type d1=Cpairs(A,(n+1)/2);
   Type d2=Cpairs(&A[(n+1)/2],n/2);
   Type p=A[(n+1)/2-1];
   Type q=A[(n+1)/2];
   d=Min(d1,d2,q-p);
   return d;
}
int main()
{
//      int a[]={3,6,1,5,7,9,2,4,
//    13,16,11,15,17,19,12,14,
//    23,26,21,25,27,29,22,24,
//    33,36,31,35,37,39,32,34,
//    43,46,41,45,47,49,42,44,
//    53,56,51,55,57,59,52,54,
//    63,66,61,65,67,69,62,64,
//    73,76,71,75,77,79,72,74,
//    83,86,81,85,87,89,82,84,
//    93,96,91,95,97,99,92,94};
//    int k=select(a,0,79,56);
//    cout<<k;
        int a[]={2,6,18,9,12};
        quickSort(a,0,4);
        cout<<Cpairs(a,5);


    return 0;
}
