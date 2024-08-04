#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int n ;
    printf("enter the array size:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array element:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the array element befor sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    selectionSort(arr, n);
    printf("\n");
     printf("enter the array element after sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
