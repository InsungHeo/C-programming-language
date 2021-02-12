#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int count)
{
    int temp;

    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < count-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    int n, m, k, total;
    int lg1, lg2;
    scanf("%d %d %d", &n, &m, &k);
    int *arr;

    // N개의 자연수 입력 받기
    for(int i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }

    // N개의 자연수를 크기 순서대로 배열 후, 가장 큰 수와 두 번째로 큰 수 골라내기
    bubble_sort(arr, n);
    lg1 = arr[n-1];
    lg2 = arr[n-2];

    total = lg1*(m-(m/(k+1))) +lg2*(m/(k+1));
    printf("%d", total);

    return 0;
}

