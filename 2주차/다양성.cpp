#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

/*�ٹ��� �پ缺�� ���ϴ� �����̴�.
�ߺ������� ���� set(����)������ ����Ͽ� �迭�� set���� ��ȯ���ش�.
set�� size�� ���ϸ� �پ缺�� return�� �� �ִ�.*/
int getElementTypeCount(int data[], int n)
{

	set<int> s(data, data+n); //data array�� set���� ��ȯ
	int countType = s.size(); // countType ������ ���� �� set.size�� �ʱ�ȭ
	return countType; // return
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
	int answer = getElementTypeCount(data, n);

	printf("%d\n", answer);

	delete[] data;
	return 0;

}