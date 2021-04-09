#include <cstdio>
#include <iostream>
#include <time.h>

using namespace std;

int gear[5][8];

void rotate_gear(int tobni_num, int direction)
{
    if (direction == 1) { //시계방향 움직임
        int tmp = gear[tobni_num][0];
        gear[tobni_num][0] = gear[tobni_num][7];
        gear[tobni_num][7] = gear[tobni_num][6];
        gear[tobni_num][6] = gear[tobni_num][5];
        gear[tobni_num][5] = gear[tobni_num][4];
        gear[tobni_num][4] = gear[tobni_num][3];
        gear[tobni_num][3] = gear[tobni_num][2];
        gear[tobni_num][2] = gear[tobni_num][1];
        gear[tobni_num][1] = tmp;
    }
    else if (direction == -1) {//반시계방향 움직임
        int tmp = gear[tobni_num][0];
        gear[tobni_num][0] = gear[tobni_num][1];
        gear[tobni_num][1] = gear[tobni_num][2];
        gear[tobni_num][2] = gear[tobni_num][3];
        gear[tobni_num][3] = gear[tobni_num][4];
        gear[tobni_num][4] = gear[tobni_num][5];
        gear[tobni_num][5] = gear[tobni_num][6];
        gear[tobni_num][6] = gear[tobni_num][7];
        gear[tobni_num][7] = tmp;
    }
}

void move_right(int n, int d) { //오른쪽 톱니바퀴 검사
    if (!(1 <= n && n <= 4)) return;

    if (gear[n - 1][2] != gear[n][6]) { 
        d = (d == 1) ? -1 : 1; //direction이 1이면 -1아니면 1 방향 변경해주는 부분
        move_right(n + 1, d);//재귀함수로 계속 오른쪽 톱니바퀴로 가면서 확인
        rotate_gear(n, d); //톱니바퀴 돌림
    }
}

void move_left(int n, int d) { //왼쪽 톱니바퀴 검사
    if (!(1 <= n && n <= 4)) return;

    if (gear[n][2] != gear[n + 1][6]) {
        d = (d == 1) ? -1 : 1;//direction 변경
        move_left(n - 1, d); //재귀함수로 왼쪽으로 가면서 확인
        rotate_gear(n, d); //톱니바퀴 돌림
    }
}

int main() {
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &gear[i][j]); //gear값들 입력 받음
        }
    }

    int cnt;
    cin >> cnt; //톱니 회전 횟수

    int* tobni_num = new int[cnt]; //몇 번째 톱니인지 저장할 동적배열 선언
    int* dir = new int[cnt]; //방향을 저장할 동적배열 선언

    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &tobni_num[i], &dir[i]); //움직일 tobni_number와 direction입력
    }
    clock_t start = clock(); //clock start 

    for (int i=0;i<cnt;i++){
        move_left(tobni_num[i] - 1, dir[i]); //왼쪽 검사
        move_right(tobni_num[i] + 1, dir[i]); // 오른쪽 검사

        rotate_gear(tobni_num[i], dir[i]); //target tobni돌림
    }
    int res;
    res = gear[1][0] + (2 * gear[2][0]) + (4 * gear[3][0]) + (8 * gear[4][0]); //점수

    cout << res;
    delete[]tobni_num; //동적할당해제
    delete[]dir;//동적할당해제
    clock_t end = clock(); //clock end
    cout.precision(11);
    cout << "\n실행시간 : " << fixed << (double)(end - start) / CLOCKS_PER_SEC << "초\n" << endl; //실행시간 출력
    return 0;
}