#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
} Point;

int ocean[52][52];

int d;

// 이동방향 수정, 0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
int changedir(d)
{
    d -= 1;
    if(d < 0)
        d += 4;
    return d;
}

// 현재 위치와 방향에서 이동할 위치를 리턴, 이동할 수 없으면 (-1, -1) 리턴
Point check(Point xy)
{
    Point mv[4] =
    {
        {-1, 0},
        {0, +1},
        {+1, 0},
        {0, -1}
    };

    // 현재 위치를 둘러싼 지점들이 전부 바다이면 (-1, -1) 리턴
    Point q = {-1,-1};
    if(ocean[xy.x + mv[0].x][xy.y + mv[0].y] == 1)
        if(ocean[xy.x + mv[1].x][xy.y + mv[1].y] == 1)
            if(ocean[xy.x + mv[2].x][xy.y + mv[2].y] == 1)
                if(ocean[xy.x + mv[3].x][xy.y + mv[3].y] == 1)
                    return q;

    // 방향부터 수정
    d = changedir(d);

    // 수정된 방향으로 한 칸 이동했을 때 육지이면 그 육지의 좌표 리턴, 육지를 바다로 변환(0 -> 1)
    if(ocean[xy.x + mv[d].x][xy.y + mv[d].y] == 0)
    {
        xy.x += mv[d].x;
        xy.y += mv[d].y;
        ocean[xy.x][xy.y] = 1;
        return xy;
    }

    // 방향을 수정해서 다시 육지 탐색
    else
        return check(xy);
}

int main()
{
    int cnt = 0;
    // 첫째 줄 입력 받기
    int n, m;
    Point xy;
    scanf("%d %d %d %d %d", &n, &m, &xy.x, &xy.y, &d);

    // 현재 위치 xy, 경계 밖으로 나가는 것을 고려하기 위해서 x,y 좌표를 1 씩 더해준다.
    xy.x += 1;
    xy.y += 1;

    // 둘째 줄 입력 받기, 0: 육지, 1: 바다, 맵 바깥 부분
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++)
        {
            if(i > 0 && i < n + 1 && j > 0 && j < m + 1)
                scanf("%d", &ocean[i][j]);
            else
                ocean[i][j] = 1;
        }

    // 시작점 바다로 변경
    ocean[xy.x][xy.y] = 1;

    // 움직일 곳이 없을 때까지 반복
    do
    {
        xy = check(xy);
        cnt ++;
    } while(xy.x != -1);

    printf("%d\n", cnt);

    return 0;
}
