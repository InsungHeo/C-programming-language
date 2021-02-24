#include <stdio.h>
#include <stdlib.h>

// typedef ����, ��ǥ ǥ��
typedef struct
{
    int x;
    int y;
}Point;

// ���� ��ġ�� ����Ʈ �������� �Է������� �� ü������ ����� 0, ����� ������ 1�� �����ϴ� �Լ�
int move(Point start, Point mv);

int main()
{
    // �̵��� �� �ִ� ����� ��
    int cnt = 0;

    // ����Ʈ�� ������
    Point mv[8] = {
        {-2, -1},
        {-2, +1},
        {-1, -2},
        {-1, +2},
        {+1, -2},
        {+1, +2},
        {+2, -1},
        {+2, +1}
    };

    // �ʱ� ��ġ �Է¹ޱ�
    char * location;
    scanf("%s", location);
    Point start;
    start.x = location[0] - ('a' - 1);
    start.y = location[1] - '0';

    // 8���� �����ӿ� ���ؼ� ����Ʈ�� ��ġ Ȯ��
    for(int i = 0; i < 8; i++)
    {
        if(move(start, mv[i]) == 1)
            cnt ++;
    }

    printf("%d", cnt);
    return 0;
}

int move(Point start, Point mv)
{
    int x = start.x + mv.x;
    int y = start.y + mv.y;
    if(x >= 1 && x <= 8)
    {
        if(y >= 1 && y <= 8)
            return 1;
        else
            return 0;
    }

    else
        return 0;
}
