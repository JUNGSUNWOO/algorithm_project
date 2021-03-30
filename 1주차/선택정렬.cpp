#include <cstdio>
#include <iostream>

using namespace std;



int getMinIndexInRange(int data[], int n, int begin, int end) //주어진 배열에서 최솟값의 위치를 찾는 함수
{
	int min = begin; // 초기 최솟값의 위치는 begin

	for (int i = begin+1; i < end+1; i++) //반복문을 돌며 data[min]이 data[i]보다 크면 min을 i로 초기화
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
		int minIndex = getMinIndexInRange(data, n, i, n-1); //getMinIndexInRange함수에서 나온 반환값과 data[i]의 위치를 바꿔줌
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
