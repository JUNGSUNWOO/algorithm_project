#include <iostream>
#include <vector>
using namespace std;

vector<int> factorize(int n) { // ���μ������ϴ� �Լ�
	vector<int> factors; // ���μ����� ����
	for (int i = 2; i * i <= n; i++) { // �ʱⰪ�� 2, ��Ʈ n���� �ݺ�
		while (n % i == 0) { // �� ������ ������������
			factors.push_back(i); // i�� ���μ����տ� �߰�
			n /= i; // n�� i�� �����ش�
		}
	}
	if (n > 1) { // ���� �۾��� ������ �����ִ� ���ڰ� 1�� �ƴ� ���
		factors.push_back(n); // �Ҽ��̹Ƿ� �߰�
	}
	return factors;
}

void process(int caseIndex) {
	int n;
	scanf("%d", &n);

	vector<int> factors = factorize(n);

	printf("#%d:\n", caseIndex);
	for (int i = 0; i < factors.size(); ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", factors[i]);
	}
	printf("\n");
}
int main() {
	int caseSize;
	cin >> caseSize; // �׽�Ʈ���̽��� ��
	for (int caseIndex = 0; caseIndex< caseSize; ++caseIndex) {
		process(caseIndex);
	} //���μ����� ����
	return 0;
}