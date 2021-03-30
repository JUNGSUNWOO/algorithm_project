#include <stdio.h>
#include <iostream>

using namespace std;

//findIndex 함수
//반복문을 돌며 data에서 m이 있으면 return 0 없으면 return -1
int findIndex(int data[], int n, int m)
{
	for (int i = 0; i < n; i++) //반복문 data를 한 바퀴 돈다
	{
		if (data[i] == m) //data[i]와 m이 같으면 반복문을 마치면 return 0
		{
			return 0;
		}
	}
	return -1; //반복문을 data[i]와 m이 같은 것이 없어 반복문을 한바퀴 끝내면 return -1
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