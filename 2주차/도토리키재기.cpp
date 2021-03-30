#include <cstdio>
#include <iostream>

using namespace std;

/*height 입력, month입력 받음
* month와 m을 비교하여 index 위치를 받아온다. in 새로운 배열
* month가 없다면 return -1
* height index위치를 비교하여 가장 큰 height return 
*/
int getMaximumHeight(int height[], int month[], int n, int m)
{
	int cnt = 0; //해당하는 month의 개수를 카운트 하기위한 변수
	int* tmp; // 해당하는 month를 저장할 배열 tmp
	tmp = new int[n]; 
	for (int i = 0; i < n; i++) //반복문 동안 month배열에 m과 일치하는 index를 tmp에 저장하고 개수 cnt를 저장
	{
		if (month[i] == m)
		{
			tmp[cnt] = i;
			cnt++;
		}
	}
	if (cnt == 0) return -1; //cnt 가 0이면 return -1
	else//cnt가 0이 아니면
	{
		int max = 0;//max 변수 선언
		for (int i = 0; i < cnt; i++) //반복문 cnt번 돌면서 max값을 찾는다
		{
			if (max < height[tmp[i]])
			{
				max = height[tmp[i]];
			}
		}
		return max;
	}
}

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &height[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m);

	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer);
	
	delete[] height;
	delete[] month;
	return 0;
}