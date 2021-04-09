#include<iostream>
#include <time.h>
#include <cstdio>
using namespace std;

/*
* 문제를 역순으로 접근한다
*  B를 2로 나누거나, 맨 뒤의 1을 제거해주는 방법으로 다가가면서
* A와 일치하면 cnt 출력, A보다 작아지면 -1 출력
*/
int AtoB(int A, int B)
{
	int cnt = 0;
	while (true)
	{
		if (A > B) //A가 B보다 크면 '-1'출력 break
		{
			return -1;
		}
		if (A == B) //A가 B와 같으면 'cnt'출력 break
		{
			cnt++;
			return cnt;
		}

		if (B % 10 == 1) //B의 마지막자리가 1이면, B 맨 오른쪽 1 제거
		{
			B--;
			B /= 10;
		}
		else if (B % 2 == 0) // B가 짝수이면 B 나누기 2
		{
			B /= 2;
		}
		else // 이외에 '-1' 출력 break
		{
			return -1;
		}

		cnt++; // 2로 나누거나 오른쪽 1을 제거할 때 마다 cnt ++;
	}
}
int main()
{
	int A, B;
	cin >> A >> B; //AB입력 받음
	clock_t start = clock(); //clock start 
	cout << AtoB(A, B);
	clock_t end = clock(); //clock end

	cout.precision(11);
	cout << "\n실행시간 : "	<< fixed << (double)(end - start)/CLOCKS_PER_SEC << "초\n" << endl; //실행시간 출력

	return 0;
}