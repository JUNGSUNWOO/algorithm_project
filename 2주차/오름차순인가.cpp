#include <cstdio>
#include <iostream>

using namespace std;

bool isOrdered(int data[], int n) 
{
	int min = data[0]; //�ʱ� �ּڰ��� data[0]���� �ʱ�ȭ
	for (int i = 1; i < n; i++) // �ݺ��� 1~n��ŭ ���鼭
	{
		if (min > data[i]) return false; //min�� data[i]���� ū��� �ݺ��� ���� & return false;
		min = data[i]; //min = data[i]�� �ʱ�ȭ

	}
	return true; //�ݺ����� �������� �Ϸ��ϸ� return true
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	bool result = isOrdered(data, n);

	if (result)
	{
		printf("yes");
	}
	else {
		printf("no");
	}

	delete[] data;
	return 0;
}

