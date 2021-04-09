#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE; //�Ǻ���ġ���̺� �������� ����

vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000; //���������������� ���� ����(8�ڸ������� ����ϱ�����)

	vector<int> ret(n + 1); //ret���� ����
	ret[1] = 0;
	ret[2] = 1; // �Ǻ���ġ������ �⺻��

	for (int i = 3; i <= n; i++) {
		ret[i] = ret[i - 1] + ret[i - 2];
		ret[i] %= MOD;
	} // �Ǻ���ġ������ ����
	return ret;
} // �Ǻ���ġ���� n��°���� MOD�� ���� ���� ���

int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n];
	return answer;
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N); // ��ó��

	int T; // �׽�Ʈ ���̽��� ��
	cin >> T;

	int* testcase = NULL;
	testcase = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> testcase[i];
	} // �׽�Ʈ���̽� �Է¹ޱ�
	for (int i = 0; i < T; i++) {
		cout << endl << getFibo(testcase[i]); //���
	}
	FIBONACCI_TABLE.clear(); //vector erase
	delete[] testcase; //�����Ҵ� ����
}