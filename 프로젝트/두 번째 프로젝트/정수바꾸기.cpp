#include<iostream>
#include <time.h>
#include <cstdio>
using namespace std;

/*
* ������ �������� �����Ѵ�
*  B�� 2�� �����ų�, �� ���� 1�� �������ִ� ������� �ٰ����鼭
* A�� ��ġ�ϸ� cnt ���, A���� �۾����� -1 ���
*/
int AtoB(int A, int B)
{
	int cnt = 0;
	while (true)
	{
		if (A > B) //A�� B���� ũ�� '-1'��� break
		{
			return -1;
		}
		if (A == B) //A�� B�� ������ 'cnt'��� break
		{
			cnt++;
			return cnt;
		}

		if (B % 10 == 1) //B�� �������ڸ��� 1�̸�, B �� ������ 1 ����
		{
			B--;
			B /= 10;
		}
		else if (B % 2 == 0) // B�� ¦���̸� B ������ 2
		{
			B /= 2;
		}
		else // �̿ܿ� '-1' ��� break
		{
			return -1;
		}

		cnt++; // 2�� �����ų� ������ 1�� ������ �� ���� cnt ++;
	}
}
int main()
{
	int A, B;
	cin >> A >> B; //AB�Է� ����
	clock_t start = clock(); //clock start 
	cout << AtoB(A, B);
	clock_t end = clock(); //clock end

	cout.precision(11);
	cout << "\n����ð� : "	<< fixed << (double)(end - start)/CLOCKS_PER_SEC << "��\n" << endl; //����ð� ���

	return 0;
}