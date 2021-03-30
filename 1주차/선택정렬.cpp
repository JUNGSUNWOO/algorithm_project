#include <cstdio>
#include <iostream>

using namespace std;



int getMinIndexInRange(int data[], int n, int begin, int end) //�־��� �迭���� �ּڰ��� ��ġ�� ã�� �Լ�
{
	int min = begin; // �ʱ� �ּڰ��� ��ġ�� begin

	for (int i = begin+1; i < end+1; i++) //�ݺ����� ���� data[min]�� data[i]���� ũ�� min�� i�� �ʱ�ȭ
	{
		if (data[min] > data[i])
		{
			min = i;
		}
	}
	return min;
}

void selectionSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{	
		int tmp;
		int minIndex = getMinIndexInRange(data, n, i, n-1); //getMinIndexInRange�Լ����� ���� ��ȯ���� data[i]�� ��ġ�� �ٲ���
		swap(data[i], data[minIndex]);
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

	selectionSort(data, n);

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
