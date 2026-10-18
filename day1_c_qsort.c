/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
int compare(const void *a ,const void *b)
{
    int k=*(const int *)a;
    int m=*(const int *)b;
    return (k>m)-(k<m);
}
int main()
{
    int arr[]={2,4,3,1,5};
    int test=sizeof(arr)/sizeof(arr[0]);
    
    qsort(arr,test,sizeof(arr[0]),compare);
    int j=0;
    for(int i=0;i<test-1;i++)
    {
      for(j=i+1;j<test;j++)
      {
        if((arr[i]+arr[j])==8)
        {
            printf("%d %d\n",i,j);
        }
      }
    }
    return 0;
}
