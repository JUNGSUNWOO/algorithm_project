#include <cstdio>
#include <iostream>

using namespace std;

bool isPrime(int N) //�Ҽ��� �Ǻ� ���ִ� �Լ�
{
	bool ans = true; //bool���� ���� true�� �ʱ�ȭ
	if (N == 1) return false; //N�� 1�� input �Ǹ� false return

	for (int i = 2; i <= N / 2; i++) //target ���� 2�� ���� ���ڱ����� �ݺ��Ѵ�. (���� ���� ����� 2�� ����̱� ������)
	{
		if (N % i == 0) //2-N/2�߿��� N�� �������� �� �������� 0�� ���� ������ �Ҽ��� �ƴ� ����
		{
			ans = false; //ans = false �� �ݺ��� Ż�� break
			break;
		}
	}
	return ans; 
}

void testcase(int caseIndex) //testcase�Լ�
{
	int n;
	scanf("%d", &n); //isPrime�Լ��� �� n�Է�

	bool result = isPrime(n); 

	printf("Case  #%d\n", caseIndex); //���° ���̽� ���
	if (result) //bool true �̸� yes false�̸� no���
	{
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}

int main()
{
	int caseSize;
	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		testcase(caseIndex);
	}
	return 0;
}