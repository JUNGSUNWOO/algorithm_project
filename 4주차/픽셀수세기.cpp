#include <cstdio>
#include <iostream>

using namespace std;

//isInside함수는 x,y좌표와 R의 거리 비교를 통해
//원의 내부에있는지를 판별한다
bool isInside(long long x, long long y, long long R)
{
	if (x * x + y * y < R * R) return true; //0,0을 기준으로 x*x + y*y이 R*R보다 작다면 원안에 있다 =>true 반환
	return false; //아니면 false 반환
}
void testcase(int caseIndex) //1사분면만을 파악하여 *4해준다
{
	long long R; //반지름 변수
	scanf("%lld", &R);
	long long sum = 0; //1사분면 안에 좌표개수를 카운트할 sum변수
	long long y = R; //y에 R저장
	for (long x = 0; x <= R; x++)//0~R반복
	{
		long long height = 0;//height변수 선언
		for (; y >= 0; y--)//y초기값은 R~0까지 반복
		{
			if (isInside(x, y, R)) { //x,y가 원안에 있다면
				height = (y + 1); //height에 y+1저장 후 break
				break; //for문의 y값이 R에서 0으로 떨어지기 때문에 isInside함수에서 처음 true나오는 지점이 최대높이이다
			}
		}
		sum += height; //sum에 height를 더해준다
	}
	printf("#%d\n", caseIndex);
	printf("%lld\n", sum * 4);//사분면이 4개이므로 *4
}

int main()
{
	int caseSize;
	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
	{
		testcase(caseIndex);
	}

	return 0;
		
}