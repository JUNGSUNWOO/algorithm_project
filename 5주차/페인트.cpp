#include <iostream>
using namespace std;
const int MAX = 100; // 색깔의 수

class Paint { //Paint 클래스 선언
public:
	int left; //클레스 멤버변수 left,right,color선언
	int right;
	int color;

	Paint() {} //빈 생성자
	Paint(int left, int right, int color) { 
		this->left = left;
		this->right = right;
		this->color = color;
	} // 생성자
};

void getAnswer(Paint* painting, int n, int m, int seat[]) {
	for (int i = 0; i < n; i++) {
		seat[i] = 0;
	} // 0으로 좌석배열 셋팅
	for (int i = 0; i < m; i++) {
		for (int j = painting[i].left; j <= painting[i].right; j++) {
			seat[j] = painting[i].color;
		} // seat 배열을 left인덱스부터 right인덱스까지 색칠
	} // m번 반복
}

int main() {
	int n, m; // 좌석의 수 n , 방법의 수 m
	cin >> n >> m;

	int maxcolor, mincolor; // 구해야 할 색의 번호

	Paint* painting = NULL;
	painting = new Paint[m]; // 색깔클래스 배열 생성

	int* seat = NULL;
	seat = new int[n]; // 좌석배열 생성

	for (int i = 0; i < m; i++) {
		cin >> painting[i].left >> painting[i].right >> painting[i].color;
		painting[i].left -= 1;
		painting[i].right -= 1;
	} // 왼쪽 좌석, 오른쪽 좌석, 색깔을 입력 받되 좌석은 1부터 시작하니까 -1씩

	getAnswer(painting, n, m, seat);

	int color[MAX] = { 0 }; // 0 ~ 99 의 인덱스를 가진 배열 생성
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < n; j++) {
			if (seat[j] == i) {
				color[i]++;
			}
		}
	} // 입력된 배열의 값들과 같은 인덱스를 ++
	int max = 0;
	for (int i = 0; i < MAX; i++) {
		if (max < color[i])
			max = color[i];
	} // color라는 배열에서 최댓값 찾기
	for (int i = 0; i < MAX; i++) {
		if (max == color[i]) {
			maxcolor = i;
			break;
		}
	} // 최댓값에 해당하는 인덱스 출력

	int min = max;
	for (int i = 0; i < MAX; i++) {
		if (min > color[i] && color[i] != 0) // 한번도 사용하지 않은 색깔 제외
			min = color[i];
	} // color라는 배열에서 최솟값 찾기
	for (int i = 0; i < MAX; i++) {
		if (min == color[i]) {
			mincolor = i;
			break;
		}
	} // 최솟값에 해당하는 인덱스 출력
	cout << maxcolor << endl << mincolor;
	delete[] painting;
}