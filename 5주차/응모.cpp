#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_SERIAL_NUMBER = 100000;

void fillFrequencyTable(const vector<int>&data, int n, vector<int>&table) {
	table.clear();
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //table 초기화 이후 resize
	for (int i = 0; i < n; ++i) { //table[data] += 1(count)
		int serial = data[i];
		table[serial] += 1;
	}
}
vector<int> getUniqueElements(const vector<int>& data, int n) {
	vector<int> ret;

	//data에 대한 빈도수 테이블을 계산한다
	vector<int> table;
	fillFrequencyTable(data, n, table);
	for (int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) {
		if (table[number] == 1) {//table[number]가 1일떄만 ret벡터에 푸쉬
			ret.push_back(number);
		}
	}
	return ret;
}
int main() {
	int n;
	cin >> n; // 삼촌팬들의 수

	vector<int> data = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	} // 시리얼 번호 입력 받기
	const vector<int> answer = getUniqueElements(data, n);//answer벡터에 getUniqueElements에서 return된 ret벡터를 저장

	for (int i = 0; i < answer.size(); ++i) { // asnwer 출력
		if (i > 0) {
			printf(" ");
		}
		printf("%d", answer[i]);
	}
	return 0;
}