#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int ocean[52][52] = {0, };
int d;

// ��������
int x[4] = {-1, 0, +1, 0};
int y[4] = {0, +1, 0, -1};

// �������� ȸ��
int changedir(d)
{
    d -= 1;
    if(d < 0)
        d += 4;
    return d;
}

// ���� ��ġ�� ������ ���� ���� �̵� ��ġ�� ����, ���� ��ġ�� ���� �ÿ��� (-1, -1) ����
Point checkloc(Point loc)
{
    // �ֺ��� �ٴ� �ۿ� ���� �ÿ� (-1, -1) ����
    Point q = {-1, -1};
    if(ocean[loc.x + x[0]][loc.y + y[0]] == 1)
        if(ocean[loc.x + x[1]][loc.y + y[1]] == 1)
            if(ocean[loc.x + x[2]][loc.y + y[2]] == 1)
                if(ocean[loc.x + x[3]][loc.y + y[3]] == 1)
                    return q;

    // �������� ���� �ٲٱ�
    d = changedir(d);

    // �� ĭ �������� �ٴ����� Ȯ��
    if(ocean[loc.x + x[d]][loc.y + y[d]] == 0)
    {
        loc.x += x[d];
        loc.y += y[d];
        ocean[loc.x][loc.y] = 1;
        return loc;
    }
    else
        return checkloc(loc);
}

int main()
{
    int n, m, cnt = 0;
    Point loc;
    scanf("%d %d %d %d %d", &n, &m, &loc.x, &loc.y, &d);

    // ������ x y�������� -1ĭ�� �̵���Ų��.
    loc.x += 1;
    loc.y += 1;
    for(int i = 0; i < 50; i++)
        for(int j = 0; j < 50; j++)
        {
            if(0 < i && i < n+1 && 0 < j && j < m+1)
                scanf("%d", &ocean[i][j]);
            else
                ocean[i][j] = 1;
        }


    // ������ �ٴٷ� ����
    ocean[loc.x][loc.y] = 1;

    do
    {
        loc = checkloc(loc);
        cnt++;
    } while(loc.x != -1);

    printf("%d", cnt);

    return 0;
}
