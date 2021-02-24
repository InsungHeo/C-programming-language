#include <stdio.h>
#include <stdlib.h>

// typedef 선언, 좌표 표시
typedef struct
{
    int x;
    int y;
}Point;

// 현재 위치와 나이트 움직임을 입력해줬을 때 체스판을 벗어나면 0, 벗어나지 않으면 1을 리턴하는 함수
int move(Point start, Point mv);

int main()
{
    // 이동할 수 있는 경우의 수
    int cnt = 0;

    // 나이트의 움직임
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

    // 초기 위치 입력받기
    char * location;
    scanf("%s", location);
    Point start;
    start.x = location[0] - ('a' - 1);
    start.y = location[1] - '0';

    // 8가지 움직임에 대해서 나이트의 위치 확인
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
