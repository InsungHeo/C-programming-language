#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);


    // N�� 1�� �� ������ ���� �ݺ�, cnt�� Ƚ�� ����.
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
