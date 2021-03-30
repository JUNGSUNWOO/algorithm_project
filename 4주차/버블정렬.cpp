#include <cstdio>
#include <iostream>

using namespace std;

//버블정렬 i가 0-n부터 한바퀴 돌면서
//가장 큰 값들을 오른쪽 부터 채워 간다
void bubbleSort(int data[], int n) //버블정렬 함수
{
	for (int i = 0; i < n; i++) //for 0~n 반복
	{
		for(int j=0;j<n-1-i;j++) //for 0~n-1-i 반복
		if (data[j] > data[j+1]) //data[j]가 data[j+1]보다 크다면 swap
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