#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ������ ũ�� N (1 <= N <= 100)
    int n, cnt = 0;
    char sb;
    scanf("%d%c", &n, &sb);

    // ��ɵ��� �迭
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

    // ��ġ ���� (x, y), (1, 1)���� ����
    int x = 1, y = 1;

    for(int i = 0; i < len; i++)
    {
        if(move[i] == 'L')
        {
            if(y != 1)
                y--;
        }
        if(move[i] == 'R')
        {
            if(y != n)
                y++;
        }
        if(move[i] == 'U')
        {
            if(x != 1)
                x--;
        }
        if(move[i] == 'D')
        {
            if(x != n)
                x++;
        }
    }

    printf("%d %d", x, y);
    return 0;
}
