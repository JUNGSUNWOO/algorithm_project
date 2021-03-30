#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//printIndexes �Լ�
//school�� �ݺ������� ���� ù��° ajou�� ������ ajou�� ã�´�
void printIndexes(string school[], int n)
{
	//���� ã������ ������ default first,last = -1
	int first = -1;
	int last = -1;

	//first�� ã�� �ݺ���
	for (int i = 0; i < n; i++) //for i=0���� n���� �ݺ�
	{
		if (school[i] == "AJOU") //AJOU�� ������ i��ġ�� first�� �����ϰ� break
		{
			first = i;
			break;
		}
	}
	for (int i = n-1; i > first; i--) //for i=n-1���� first���� �������� �ݺ�
	{
		if (school[i] == "AJOU") // AJOU�� ������ i ��ġ�� last�� �����ϰ� break
		{
			last = i;
			break;
		}
	}

	printf("%d, %d\n", first+1, last+1); //�迭�� 0���� �����ϹǷ� first, last�� +1�� ���ؼ� return
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
