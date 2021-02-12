#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);


    // N이 1이 될 때까지 연산 반복, cnt로 횟수 측정.
    while(1)
    {
        if(n == 1)
            break;
        if(n%k == 0)
        {
            n /= k;
            cnt ++;
        }
        else
        {
            n--;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
