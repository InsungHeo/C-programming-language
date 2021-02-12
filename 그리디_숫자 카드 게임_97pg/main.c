#include <stdio.h>
#include <stdlib.h>

// 배열에서 가장 작은 수와 가장 큰 수를 뽑아내는 함수
int smallnum(int arr[], int n);
int bignum(int arr[], int n);

int main()
{
    // N, M, 모든 카드 숫자들 입력받기
    int n, m;
    int k;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    }

    // 각 행마다 가장 작은 숫자들로 만든 새로운 배열 narr
    int narr[n];
    for(int i = 0; i < n; i++)
    {
        narr[i] = smallnum(arr[i], m);
    }

    k = bignum(narr, n);
    printf("%d", k);
    return 0;
}

int smallnum(int arr[], int n)
{
    int s = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < s)
            s = arr[i];
    }
    return s;
}

int bignum(int arr[], int n)
{
    int l = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > l)
            l = arr[i];
    }
    return l;
}
