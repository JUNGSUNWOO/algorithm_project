#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//printIndexes 함수
//school을 반복문으로 돌며 첫번째 ajou와 마지막 ajou를 찾는다
void printIndexes(string school[], int n)
{
	//값이 찾아지지 않을때 default first,last = -1
	int first = -1;
	int last = -1;

	//first를 찾는 반복문
	for (int i = 0; i < n; i++) //for i=0부터 n까지 반복
	{
		if (school[i] == "AJOU") //AJOU가 있으면 i위치를 first에 저장하고 break
		{
			first = i;
			break;
		}
	}
	for (int i = n-1; i > first; i--) //for i=n-1부터 first까지 역순으로 반복
	{
		if (school[i] == "AJOU") // AJOU가 있으면 i 위치를 last에 저장하고 break
		{
			last = i;
			break;
		}
	}

	printf("%d, %d\n", first+1, last+1); //배열은 0부터 시작하므로 first, last에 +1씩 더해서 return
}

int main()
{
	int n;
	char buff[11];
	string* school;

	scanf("%d", &n);
	school = new string[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%s", buff);
		school[i] = buff;
	}

	printIndexes(school, n);

	delete[] school;
	return 0;
}
