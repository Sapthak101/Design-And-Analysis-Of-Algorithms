#include<stdio.h>

void insert(int A[], int n)
{
    int temp, i=0;
    i=n;
    temp=A[n];

    while (i>1 && temp>A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int main()
{
    int A[]={0,10,20,30,25,5,40,35};
    for (int i=1; i<=7; i++)
        insert(A, i);
    for (int i=1; i<=7; i++)
        printf("%d\n", A[i]);

    return 0;
}