#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 공간의 크기 N (1 <= N <= 100)
    int n, cnt = 0;
    char sb;
    scanf("%d%c", &n, &sb);

    // 명령들의 배열
    char move[100];
    int len = 0;
    for(int i = 0; i < 100; i++)
    {
        len++;
        move[i] = getchar();
        sb = getchar();
        if(sb == '\n')
            break;
    }

    // 위치 정보 (x, y), (1, 1)에서 시작
    int x = 1, y = 1;

    for(int i = 0; i < len; i++)
    {
        if(move[i] == 'L')
        {
            if(x != 1)
                x--;
        }
        if(move[i] == 'R')
        {
            if(x != n)
                x++;
        }
        if(move[i] == 'U')
        {
            if(y != 1)
                y--;
        }
        if(move[i] == 'D')
        {
            if(y != n)
                y++;
        }
    }

    printf("%d %d", x, y);
    return 0;
}
