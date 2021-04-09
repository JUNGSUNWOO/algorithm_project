#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE; //피보나치테이블 전역변수 선언

vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000; //나머지연산을위한 변수 선언(8자리까지만 출력하기위해)

	vector<int> ret(n + 1); //ret벡터 선언
	ret[1] = 0;
	ret[2] = 1; // 피보나치수열의 기본값

	for (int i = 3; i <= n; i++) {
		ret[i] = ret[i - 1] + ret[i - 2];
		ret[i] %= MOD;
	} // 피보나치수열의 정의
	return ret;
} // 피보나치수열 n번째항을 MOD로 나눈 값을 출력

int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n];
	return answer;
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N); // 전처리

	int T; // 테스트 케이스의 수
	cin >> T;

	int* testcase = NULL;
	testcase = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> testcase[i];
	} // 테스트케이스 입력받기
	for (int i = 0; i < T; i++) {
		cout << endl << getFibo(testcase[i]); //출력
	}
	FIBONACCI_TABLE.clear(); //vector erase
	delete[] testcase; //동적할당 해제
}