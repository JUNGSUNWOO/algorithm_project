#include <cstdio>
#include <iostream>

using namespace std;

int getRangeSumFromOne(int i) //1�̻� i������ �ڿ����� ���� ���ϴ� �Լ�
{
	int sum = 0;
	for (int j = 0; j <= i; j++)
	{
		sum += j;
	}
	return sum;
}

long long getAnswer(int N) //getRangeSumFromOne�Լ����� ������ 1~i�� �յ��� ���ϴ� �Լ�
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