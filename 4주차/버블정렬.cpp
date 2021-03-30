#include <cstdio>
#include <iostream>

using namespace std;

//�������� i�� 0-n���� �ѹ��� ���鼭
//���� ū ������ ������ ���� ä�� ����
void bubbleSort(int data[], int n) //�������� �Լ�
{
	for (int i = 0; i < n; i++) //for 0~n �ݺ�
	{
		for(int j=0;j<n-1-i;j++) //for 0~n-1-i �ݺ�
		if (data[j] > data[j+1]) //data[j]�� data[j+1]���� ũ�ٸ� swap
		{
			int tmp = data[j];
			data[j] = data[j + 1];
			data[j + 1] = tmp;
		}
	}
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

	bubbleSort(data, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%d", data[i]);
	}

	delete[] data;
	return 0;
}