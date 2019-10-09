#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int *left=(int*)malloc(100*sizeof(int));
int *right=(int*)malloc(100*sizeof(int));
    for (i = 0; i < n1; i++)
        *(left+i) = *(arr+l+i);
    for (j = 0; j < n2; j++)
        *(right+j)=*(arr+m + 1+ j);



    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (*(left+i) <= *(right+j))
        {
            *(arr+k)=*(left+i);

            i++;
        }
        else
        {
            *(arr+k) = *(right+j);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        *(arr+k)=*(left+i);
        i++;
        k++;
    }

    while (j < n2)
    {
        *(arr+k) = *(right+j);
        j++;
        k++;
    }

    free(left);
    free(right);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main()
{

    int n;
    printf("Enter the number of elements you want to give input :  ");
    scanf("%d",&n);
    int i=0;
    int * arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    mergeSort(arr,0,n-1);
    printf("Array after performing MERGE SORT :: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    free(arr);
}
