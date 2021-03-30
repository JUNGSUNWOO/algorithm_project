#include <cstdio>
#include <iostream>

using namespace std;

int getRangeSumFromOne(int i) //1이상 i이하의 자연수의 합을 구하는 함수
{
	int sum = 0;
	for (int j = 0; j <= i; j++)
	{
		sum += j;
	}
	return sum;
}

long long getAnswer(int N) //getRangeSumFromOne함수에서 구해진 1~i의 합들을 합하는 함수
{
	int sum = 0;
	for (int i = 0; i <= N; i++)
	{
		sum += getRangeSumFromOne(i);
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);

	long long answer = getAnswer(n);
	printf("%lld\n", answer);

	return 0;
}