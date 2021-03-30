#include <stdio.h>
#include <iostream>

using namespace std;

//solve �Լ�
//1. data�� p���� �۰ų� ���� ������ ã�� sum�� �����ָ�, cnt += 1���ش�.
//2. sum�� q�� ���Ͽ� �Բ� ž���� �������� ���θ� ������ش�

void solve(int data[], int n, int p, int q)
{
	int cnt = 0; // ž�°����� �������� �ο� count�� ���� ����
	int sum = 0; // ž�°����� �������� �ο����� ���� �� ����� ���� ����
	for (int i = 0; i < n; i++) // data�� ������ŭ for���� ���� data[i]�� �δ� �������� p�� ���Ѵ�
	{
		if (data[i] <= p) { //p���� �����԰� �۰ų� ���� ������� ã�´�
			sum += data[i]; // ã�� ������� ���Ը� ���Ѵ�
			cnt++; // �� ������� count ���ش�
		}
	}

	//print
	printf("%d %d\n", cnt, sum); //�� �ο�, ���� ��
	if (sum > q) printf("no"); //���� ž�� �������� ����
	else printf("yes");
}

int main()
{
	int n, p, q; //n = �ִ� �ο���, p = 1�� �ִ� ����, q = ž���ο� �ִ빫��
	int* data; //�� �ο��� ���� ������

	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	solve(data, n, p, q);

	delete[] data;
	return 0;
}