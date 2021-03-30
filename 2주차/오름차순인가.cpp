#include <cstdio>
#include <iostream>

using namespace std;

bool isOrdered(int data[], int n) 
{
	int min = data[0]; //초기 최솟값을 data[0]으로 초기화
	for (int i = 1; i < n; i++) // 반복문 1~n만큼 돌면서
	{
		if (min > data[i]) return false; //min이 data[i]보다 큰경우 반복문 종료 & return false;
		min = data[i]; //min = data[i]로 초기화

	}
	return true; //반복문을 문제없이 완료하면 return true
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

