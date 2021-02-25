#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int ocean[52][52] = {0, };
int d;

// 동서남북
int x[4] = {-1, 0, +1, 0};
int y[4] = {0, +1, 0, -1};

// 왼쪽으로 회전
int changedir(d)
{
    d -= 1;
    if(d < 0)
        d += 4;
    return d;
}

// 현재 위치와 방향을 통해 다음 이동 위치를 리턴, 다음 위치가 없을 시에는 (-1, -1) 리턴
Point checkloc(Point loc)
{
    // 주변에 바다 밖에 없을 시에 (-1, -1) 리턴
    Point q = {-1, -1};
    if(ocean[loc.x + x[0]][loc.y + y[0]] == 1)
        if(ocean[loc.x + x[1]][loc.y + y[1]] == 1)
            if(ocean[loc.x + x[2]][loc.y + y[2]] == 1)
                if(ocean[loc.x + x[3]][loc.y + y[3]] == 1)
                    return q;

    // 왼쪽으로 방향 바꾸기
    d = changedir(d);

    // 옆 칸 윶기인지 바다인지 확인
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

    // 원점을 x y방향으로 -1칸씩 이동시킨다.
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


    // 시작점 바다로 변경
    ocean[loc.x][loc.y] = 1;

    do
    {
        loc = checkloc(loc);
        cnt++;
    } while(loc.x != -1);

    printf("%d", cnt);

    return 0;
}
