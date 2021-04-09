#include <iostream>
using namespace std;

const int MAX = 10000;

int getFrequency(int arr[], int n) {
	int phone[MAX] = { 0 }; // 0 ~ 9999 �� �ε����� ���� �迭 ���� -> phone�迭�� ���ڸ��� �ش��ϴ� �迭 index�� ++�����μ�
	//���ڸ� ��ȣ �������� count�Ѵ�
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] == i) {
				phone[i]++;
			}
		}
	} // �Էµ� �迭�� ����� ���� �ε����� ++
	int max = 0;
	for (int i = 0; i < MAX; i++) {
		if (max < phone[i])
			max = phone[i];
	} // phone�̶�� �迭�� �� �ִ� ã��
	for (int i = 0; i < MAX; i++) {
		if (max == phone[i])
			return i;
	} // �ִ񰪿� �ش��ϴ� �ε��� ���
}


int main() {
	int n; // ��ȭ��ȣ ����
	cin >> n;

	int* number = NULL; //���� �Ҵ�
	number = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	} // �Է¹��� ��ȭ��ȣ �迭

	printf("%04d", getFrequency(number, n));

	delete[] number; //���� �Ҵ� ����
}