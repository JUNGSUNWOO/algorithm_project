#include <iostream>
using namespace std;
const int MAX = 100; // ������ ��

class Paint { //Paint Ŭ���� ����
public:
	int left; //Ŭ���� ������� left,right,color����
	int right;
	int color;

	Paint() {} //�� ������
	Paint(int left, int right, int color) { 
		this->left = left;
		this->right = right;
		this->color = color;
	} // ������
};

void getAnswer(Paint* painting, int n, int m, int seat[]) {
	for (int i = 0; i < n; i++) {
		seat[i] = 0;
	} // 0���� �¼��迭 ����
	for (int i = 0; i < m; i++) {
		for (int j = painting[i].left; j <= painting[i].right; j++) {
			seat[j] = painting[i].color;
		} // seat �迭�� left�ε������� right�ε������� ��ĥ
	} // m�� �ݺ�
}

int main() {
	int n, m; // �¼��� �� n , ����� �� m
	cin >> n >> m;

	int maxcolor, mincolor; // ���ؾ� �� ���� ��ȣ

	Paint* painting = NULL;
	painting = new Paint[m]; // ����Ŭ���� �迭 ����

	int* seat = NULL;
	seat = new int[n]; // �¼��迭 ����

	for (int i = 0; i < m; i++) {
		cin >> painting[i].left >> painting[i].right >> painting[i].color;
		painting[i].left -= 1;
		painting[i].right -= 1;
	} // ���� �¼�, ������ �¼�, ������ �Է� �޵� �¼��� 1���� �����ϴϱ� -1��

	getAnswer(painting, n, m, seat);

	int color[MAX] = { 0 }; // 0 ~ 99 �� �ε����� ���� �迭 ����
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < n; j++) {
			if (seat[j] == i) {
				color[i]++;
			}
		}
	} // �Էµ� �迭�� ����� ���� �ε����� ++
	int max = 0;
	for (int i = 0; i < MAX; i++) {
		if (max < color[i])
			max = color[i];
	} // color��� �迭���� �ִ� ã��
	for (int i = 0; i < MAX; i++) {
		if (max == color[i]) {
			maxcolor = i;
			break;
		}
	} // �ִ񰪿� �ش��ϴ� �ε��� ���

	int min = max;
	for (int i = 0; i < MAX; i++) {
		if (min > color[i] && color[i] != 0) // �ѹ��� ������� ���� ���� ����
			min = color[i];
	} // color��� �迭���� �ּڰ� ã��
	for (int i = 0; i < MAX; i++) {
		if (min == color[i]) {
			mincolor = i;
			break;
		}
	} // �ּڰ��� �ش��ϴ� �ε��� ���
	cout << maxcolor << endl << mincolor;
	delete[] painting;
}