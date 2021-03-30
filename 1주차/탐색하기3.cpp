#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int findIndex(int data[], int n)
{
	int sum = 0; //����� ���ϱ� ���� �� ����
	float avg = 0; // ��� ����

	for (int i = 0; i < n; i++) //sum ���ϱ�
	{
		sum += data[i];
	}

	avg = sum / n; //avg ���ϱ�
	printf("%f", avg);
	int min = abs(data[0] - avg); // min �ʱⰪ
	int index; // index ��ġ ���� ����
	int answer;// answer ���� ����
	for (int i = 1; i < n; i++) // data[i] - avg�� ���밪�� ���ϸ� ���� ���� ���� min�� �����Ѵ�
	{
		int tmp = abs(data[i] - avg);
		if (min > tmp)
		{
			min = tmp;//min�� �ʱ�ȭ �� ��, answer, index ������ Ÿ�� �� ����
			answer = data[i];
			index = i;
		}
	}
	printf("%d ", index + 1); // index��ġ ��� 0���� �����ϹǷ� +1���ش�
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