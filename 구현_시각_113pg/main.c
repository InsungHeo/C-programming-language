#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 00시 00분 00초부터 N시 59분 59초까지       3 포함 여부 확인
    int n;
    scanf("%d", &n);
    int cnt = 0;

    // 모든 시간에 대해서 3이 들어있는지를 확인한다
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < 60; j++)
            for(int k = 0; k < 60; k++)
            {
                if(i%10 == 3 || (i-i%10)/10 == 3)
                {
                    cnt++;
                    continue;
                }
                if(j%10 == 3 || (j-j%10)/10 == 3)
                {
                    cnt++;
                    continue;
                }
                if(k%10 == 3|| (k-k%10)/10 == 3)
                    cnt++;
            }
    printf("%d", cnt);
    return 0;
}




