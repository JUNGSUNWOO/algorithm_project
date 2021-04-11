#include <iostream> 
using namespace std;

const int MAX_ROW = 9; //9 by 9 ��ļ���
const int MAX_COL = 9; //9 by 9 ��ļ���

class SudokuBoard { //������ Ŭ���� ����
public:
	int getRowByIndex(int index) { //�� ���� ��ȯ �ϴ� �Լ�
		return (index - 1) % 9 + 1; //������ ����
	}
	int getColByIndex(int index) { //�� ���� ��ȯ �ϴ� �Լ�
		return (index - 1) / 9 + 1; //�� ����
	}
	int getGroupByIndex(int index) { //��, ������ ���� position���� ��ȯ�ϴ� �Լ�
		int r = getRowByIndex(index);
		int c = getColByIndex(index);
		return getGroupByPosition(r, c);
	}
	int getGroupByPosition(int row, int column) { //row, column ������ group position�� ��ȯ�ϴ� �Լ�
		int offset = ((column - 1) / 3) * 3 + 1; //�� ������ offset�� ���� -> ������ �󿡼� ���� Ŀ���� �׷��� ����Ŀ��
		int left = (row - 1) / 3; //�� ������ left�� ���� -> ������ �󿡼� ���� Ŀ���� �׷��� ������ Ŀ��
		return left + offset; //left + offset => group number
	}
	int getIndexByPosition(int row, int column) { //row,column ������ index position�� ��ȯ�ϴ� �Լ�
		return (row - 1) * 9 + (column - 1) % 9 + 1;
	}
};

void process(int caseIndex) {
	int index;
	scanf("%d", &index);

	SudokuBoard board = SudokuBoard();

	int row = board.getRowByIndex(index);
	int col = board.getColByIndex(index);
	int group = board.getGroupByIndex(index);

	printf("Case #%d:\n", caseIndex);
	printf("%d %d %d\n", row, col, group);
}

int main() {
	int caseSize; //caseSize ���� ����
	scanf("%d", &caseSize);

	//�ݺ����� ���� case 1���� caseSize������ ��� Ȯ��
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}
