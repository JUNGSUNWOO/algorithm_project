#include <cstdio>
#include <iostream>

using namespace std;

bool isPrime(int N) //소수를 판별 해주는 함수
{
	bool ans = true; //bool변수 선언 true로 초기화
	if (N == 1) return false; //N에 1이 input 되면 false return

	for (int i = 2; i <= N / 2; i++) //target 수를 2로 나눈 숫자까지만 반복한다. (가장 작은 배수가 2의 배수이기 때문에)
	{
		if (N % i == 0) //2-N/2중에서 N을 나누었을 때 나머지가 0인 수가 나오면 소수가 아닌 것임
		{
			ans = false; //ans = false 후 반복문 탈출 break
			break;
		}
	}
	return ans; 
}

void testcase(int caseIndex) //testcase함수
{
	int n;
	scanf("%d", &n); //isPrime함수에 들어갈 n입력

	bool result = isPrime(n); 

	printf("Case  #%d\n", caseIndex); //몇번째 케이스 출력
	if (result) //bool true 이면 yes false이면 no출력
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