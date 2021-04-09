#include <cstdio>
#include <iostream>
#include <time.h>

using namespace std;

int gear[5][8];

void rotate_gear(int tobni_num, int direction)
{
    if (direction == 1) { //�ð���� ������
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
    else if (direction == -1) {//�ݽð���� ������
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

void move_right(int n, int d) { //������ ��Ϲ��� �˻�
    if (!(1 <= n && n <= 4)) return;

    if (gear[n - 1][2] != gear[n][6]) { 
        d = (d == 1) ? -1 : 1; //direction�� 1�̸� -1�ƴϸ� 1 ���� �������ִ� �κ�
        move_right(n + 1, d);//����Լ��� ��� ������ ��Ϲ����� ���鼭 Ȯ��
        rotate_gear(n, d); //��Ϲ��� ����
    }
}

void move_left(int n, int d) { //���� ��Ϲ��� �˻�
    if (!(1 <= n && n <= 4)) return;

    if (gear[n][2] != gear[n + 1][6]) {
        d = (d == 1) ? -1 : 1;//direction ����
        move_left(n - 1, d); //����Լ��� �������� ���鼭 Ȯ��
        rotate_gear(n, d); //��Ϲ��� ����
    }
}

int main() {
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%1d", &gear[i][j]); //gear���� �Է� ����
        }
    }

    int cnt;
    cin >> cnt; //��� ȸ�� Ƚ��

    int* tobni_num = new int[cnt]; //�� ��° ������� ������ �����迭 ����
    int* dir = new int[cnt]; //������ ������ �����迭 ����

    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &tobni_num[i], &dir[i]); //������ tobni_number�� direction�Է�
    }
    clock_t start = clock(); //clock start 

    for (int i=0;i<cnt;i++){
        move_left(tobni_num[i] - 1, dir[i]); //���� �˻�
        move_right(tobni_num[i] + 1, dir[i]); // ������ �˻�

        rotate_gear(tobni_num[i], dir[i]); //target tobni����
    }
    int res;
    res = gear[1][0] + (2 * gear[2][0]) + (4 * gear[3][0]) + (8 * gear[4][0]); //����

    cout << res;
    delete[]tobni_num; //�����Ҵ�����
    delete[]dir;//�����Ҵ�����
    clock_t end = clock(); //clock end
    cout.precision(11);
    cout << "\n����ð� : " << fixed << (double)(end - start) / CLOCKS_PER_SEC << "��\n" << endl; //����ð� ���
    return 0;
}