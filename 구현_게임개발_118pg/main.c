#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
} Point;

int ocean[52][52];

int d;

// �̵����� ����, 0: ����, 1: ����, 2: ����, 3: ����
int changedir(d)
{
    d -= 1;
    if(d < 0)
        d += 4;
    return d;
}

// ���� ��ġ�� ���⿡�� �̵��� ��ġ�� ����, �̵��� �� ������ (-1, -1) ����
Point check(Point xy)
{
    Point mv[4] =
    {
        {-1, 0},
        {0, +1},
        {+1, 0},
        {0, -1}
    };

    // ���� ��ġ�� �ѷ��� �������� ���� �ٴ��̸� (-1, -1) ����
    Point q = {-1,-1};
    if(ocean[xy.x + mv[0].x][xy.y + mv[0].y] == 1)
        if(ocean[xy.x + mv[1].x][xy.y + mv[1].y] == 1)
            if(ocean[xy.x + mv[2].x][xy.y + mv[2].y] == 1)
                if(ocean[xy.x + mv[3].x][xy.y + mv[3].y] == 1)
                    return q;

    // ������� ����
    d = changedir(d);

    // ������ �������� �� ĭ �̵����� �� �����̸� �� ������ ��ǥ ����, ������ �ٴٷ� ��ȯ(0 -> 1)
    if(ocean[xy.x + mv[d].x][xy.y + mv[d].y] == 0)
    {
        xy.x += mv[d].x;
        xy.y += mv[d].y;
        ocean[xy.x][xy.y] = 1;
        return xy;
    }

    // ������ �����ؼ� �ٽ� ���� Ž��
    else
        return check(xy);
}

int main()
{
    int cnt = 0;
    // ù° �� �Է� �ޱ�
    int n, m;
    Point xy;
    scanf("%d %d %d %d %d", &n, &m, &xy.x, &xy.y, &d);

    // ���� ��ġ xy, ��� ������ ������ ���� ����ϱ� ���ؼ� x,y ��ǥ�� 1 �� �����ش�.
    xy.x += 1;
    xy.y += 1;

    // ��° �� �Է� �ޱ�, 0: ����, 1: �ٴ�, �� �ٱ� �κ�
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++)
        {
            if(i > 0 && i < n + 1 && j > 0 && j < m + 1)
                scanf("%d", &ocean[i][j]);
            else
                ocean[i][j] = 1;
        }

    // ������ �ٴٷ� ����
    ocean[xy.x][xy.y] = 1;

    // ������ ���� ���� ������ �ݺ�
    do
    {
        xy = check(xy);
        cnt ++;
    } while(xy.x != -1);

    printf("%d\n", cnt);

    return 0;
}
