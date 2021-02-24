#include <stdio.h>
#include <stdlib.h>
// ���� ��ġ�� ����Ʈ �������� �Է������� �� ü������ ����� 0, ����� ������ 1�� �����ϴ� �Լ�
int move(int l[], int m[]);

int main()
{
    // �̵��� �� �ִ� ����� ��
    int cnt = 0;

    // ����Ʈ�� ������
    int mv[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    // �ʱ� ��ġ �Է¹ޱ�
    char * location;
    scanf("%s", location);
    int x = location[0] - ('a'-1);
    int y = location[1] - '0';
    int l[2] = {x, y};

    // 8���� �����ӿ� ���ؼ� ����Ʈ�� ��ġ Ȯ��
    for(int i = 0; i < 8; i++)
    {
        if(move(l, mv[i]) == 1)
            cnt ++;
    }

    printf("%d", cnt);
    return 0;
}

int move(int *l, int *m)
{
    int x = l[0] + m[0];
    int y = l[1] + m[1];
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
