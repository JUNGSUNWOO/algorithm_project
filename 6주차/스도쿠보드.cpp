#include <iostream> 
using namespace std;

const int MAX_ROW = 9; //9 by 9 행렬선언
const int MAX_COL = 9; //9 by 9 행렬선언

class SudokuBoard { //스도쿠 클래스 선언
public:
	int getRowByIndex(int index) { //행 값을 반환 하는 함수
		return (index - 1) % 9 + 1; //나머지 연산
	}
	int getColByIndex(int index) { //열 값을 반환 하는 함수
		return (index - 1) / 9 + 1; //몫 연산
	}
	int getGroupByIndex(int index) { //행, 열값을 통해 position값을 반환하는 함수
		int r = getRowByIndex(index);
		int c = getColByIndex(index);
		return getGroupByPosition(r, c);
	}
	int getGroupByPosition(int row, int column) { //row, column 정보로 group position을 반환하는 함수
		int offset = ((column - 1) / 3) * 3 + 1; //열 정보로 offset값 얻음 -> 스도쿠 상에서 열은 커지면 그룹이 빨리커짐
		int left = (row - 1) / 3; //행 정보로 left값 얻음 -> 스도쿠 상에서 행은 커져도 그룹이 느리게 커짐
		return left + offset; //left + offset => group number
	}
	int getIndexByPosition(int row, int column) { //row,column 정보로 index position을 반환하는 함수
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
	int caseSize; //caseSize 변수 선언
	scanf("%d", &caseSize);

	//반복문을 통해 case 1부터 caseSize까지의 결과 확인
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}
