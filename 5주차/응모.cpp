#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_SERIAL_NUMBER = 100000;

void fillFrequencyTable(const vector<int>&data, int n, vector<int>&table) {
	table.clear();
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //table �ʱ�ȭ ���� resize
	for (int i = 0; i < n; ++i) { //table[data] += 1(count)
		int serial = data[i];
		table[serial] += 1;
	}
}
vector<int> getUniqueElements(const vector<int>& data, int n) {
	vector<int> ret;

	//data�� ���� �󵵼� ���̺��� ����Ѵ�
	vector<int> table;
	fillFrequencyTable(data, n, table);
	for (int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) {
		if (table[number] == 1) {//table[number]�� 1�ϋ��� ret���Ϳ� Ǫ��
			ret.push_back(number);
		}
	}
	return ret;
}
int main() {
	int n;
	cin >> n; // �����ҵ��� ��

	vector<int> data = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	} // �ø��� ��ȣ �Է� �ޱ�
	const vector<int> answer = getUniqueElements(data, n);//answer���Ϳ� getUniqueElements���� return�� ret���͸� ����

	for (int i = 0; i < answer.size(); ++i) { // asnwer ���
		if (i > 0) {
			printf(" ");
		}
		printf("%d", answer[i]);
	}
	return 0;
}