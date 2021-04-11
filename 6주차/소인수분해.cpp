#include <iostream>
#include <vector>
using namespace std;

vector<int> factorize(int n) { // 소인수분해하는 함수
	vector<int> factors; // 소인수들의 집합
	for (int i = 2; i * i <= n; i++) { // 초기값은 2, 루트 n까지 반복
		while (n % i == 0) { // 다 나누어 떨어질때까지
			factors.push_back(i); // i를 소인수집합에 추가
			n /= i; // n을 i로 나눠준다
		}
	}
	if (n > 1) { // 위에 작업이 끝나고 남아있는 숫자가 1이 아닌 경우
		factors.push_back(n); // 소수이므로 추가
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
	cin >> caseSize; // 테스트케이스의 수
	for (int caseIndex = 0; caseIndex< caseSize; ++caseIndex) {
		process(caseIndex);
	} //소인수분해 진행
	return 0;
}