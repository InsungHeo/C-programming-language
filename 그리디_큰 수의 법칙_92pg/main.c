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

    // N���� �ڿ��� �Է� �ޱ�
    for(int i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }

    // N���� �ڿ����� ũ�� ������� �迭 ��, ���� ū ���� �� ��°�� ū �� ��󳻱�
    bubble_sort(arr, n);
    lg1 = arr[n-1];
    lg2 = arr[n-2];

    total = lg1*(m-(m/(k+1))) +lg2*(m/(k+1));
    printf("%d", total);

    return 0;
}

