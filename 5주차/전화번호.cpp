#include <iostream>
using namespace std;

const int MAX = 10000;

int getFrequency(int arr[], int n) {
	int phone[MAX] = { 0 }; // 0 ~ 9999 의 인덱스를 가진 배열 생성 -> phone배열에 끝자리에 해당하는 배열 index에 ++함으로서
	//끝자리 번호 개수들을 count한다
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] == i) {
				phone[i]++;
			}
		}
	} // 입력된 배열의 값들과 같은 인덱스를 ++
	int max = 0;
	for (int i = 0; i < MAX; i++) {
		if (max < phone[i])
			max = phone[i];
	} // phone이라는 배열값 중 최댓값 찾기
	for (int i = 0; i < MAX; i++) {
		if (max == phone[i])
			return i;
	} // 최댓값에 해당하는 인덱스 출력
}


int main() {
	int n; // 전화번호 갯수
	cin >> n;

	int* number = NULL; //동적 할당
	number = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	} // 입력받은 전화번호 배열

	printf("%04d", getFrequency(number, n));

	delete[] number; //동적 할당 해제
}