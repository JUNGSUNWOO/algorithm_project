#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int findIndex(int data[], int n)
{
	int sum = 0; //평균을 구하기 위한 합 변수
	float avg = 0; // 평균 변수

	for (int i = 0; i < n; i++) //sum 구하기
	{
		sum += data[i];
	}

	avg = sum / n; //avg 구하기
	printf("%f", avg);
	int min = abs(data[0] - avg); // min 초기값
	int index; // index 위치 저장 변수
	int answer;// answer 저장 변수
	for (int i = 1; i < n; i++) // data[i] - avg의 절대값을 비교하며 가장 작은 값을 min에 저장한다
	{
		int tmp = abs(data[i] - avg);
		if (min > tmp)
		{
			min = tmp;//min이 초기화 될 때, answer, index 변수에 타겟 값 저장
			answer = data[i];
			index = i;
		}
	}
	printf("%d ", index + 1); // index위치 출력 0부터 시작하므로 +1해준다
	return answer; //return answer
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
	
	int answer = findIndex(data, n);
	printf("%d", answer);

	delete[] data;
	return 0;
}