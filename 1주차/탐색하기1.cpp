#include <stdio.h>
#include <iostream>

using namespace std;

//findIndex �Լ�
//�ݺ����� ���� data���� m�� ������ return 0 ������ return -1
int findIndex(int data[], int n, int m)
{
	for (int i = 0; i < n; i++) //�ݺ��� data�� �� ���� ����
	{
		if (data[i] == m) //data[i]�� m�� ������ �ݺ����� ��ġ�� return 0
		{
			return 0;
		}
	}
	return -1; //�ݺ����� data[i]�� m�� ���� ���� ���� �ݺ����� �ѹ��� ������ return -1
}

int main()
{
	int n, m;
	int* data;

	scanf("%d %d", &n, &m);
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	int answer = findIndex(data, n, m);

	printf("%d\n", answer);
	delete[] data;
	return 0;
}