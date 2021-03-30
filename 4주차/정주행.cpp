#include <cstdio>
#include <iostream>

using namespace std;

bool isConsecutive(int data[], int n) //�������� ������ ǥ���� �� �ִ��� �Ǵ��ϴ� �Լ�
{//data�迭���� �ִ밪�� �ּҰ��� ���� ��
	//�ִ밪 - �ּڰ��� �迭 size -1�� ��ġ�Ѵٸ�
	//�������� ������ �̷�ٰ� �� �� �ִ�
	int max_data = data[0]; //�ִ밪 ���� ���� �� �ʱ�ȭ
	int min_data = data[0]; //�ּҰ� ���� ���� �� �ʱ�ȭ
	for (int i = 1; i < n; i++) //1~n���� �ݺ�
	{
		if (max_data < data[i]) max_data = data[i]; //max �� ���ϱ�
		if (min_data > data[i]) min_data = data[i]; //min �� ���ϱ�
	}
	if (max_data - min_data == n - 1) return true; //max-min�� �迭size-1�� ���ٸ� true
	return false;//�ƴϸ� false
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
	bool result = isConsecutive(data, n);

	if (result) printf("Yes");
	else printf("No");

	delete[] data;
	return 0;
}