#include <iostream>
#include <vector>
using namespace std;

class TicketTable { //TicketTable 클래스 선언
public:
	vector<bool> used; //tickettable에서 사용중인 length인지 확인을 위한 bool형 vector 선언
	int length;
	TicketTable(int length) { //생성자
		this->length = length;
		this->used.assign(length, false);
	}

	int findEmptyIndexByUserId(int userId) { //userId를 통해 빈 index인지 찾는 메소드
		int index = userId % length; // index = userId를 length로 나눈 나머지
		while (this->isEmpty(index) == true) { // 비어있을 때 까지 index = (index + 1) % length
			index = (index + 1) % length;
		}
		return index; 
	}

	bool isEmpty(int ticketIndex) { //비어있는지 확인하는 메소드
		return this->used[ticketIndex];
	}
	void setUsed(int index, bool status) { //비어있는 걸 확인 한 뒤 해당 인덱스로 status를 false에서 true로 바꿔줌
		this->used[index] = status;
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) { //Ticketnumber를 반환하는 메소드
	vector<int> tickets; // tickets 벡터 선언
	TicketTable table = TicketTable(n); //ticketTable 선언

	for (int i = 0; i < m; i++) { // 반복문을 m번 돌며 ids값들을 이용하여 table을 채운다
		int userId = ids[i]; //ids배열에서 userid 저장
		int ticketIndex = table.findEmptyIndexByUserId(userId); //userid를 통해 비어있는 index 확인
		tickets.push_back(ticketIndex); //userid로 찾은 ticketindex를 ticket 벡터에 push
		table.setUsed(ticketIndex, true); //index에 해당하는 table을 setused 상태로 변경
	}
	return tickets; 
}

int main() {
	int n, m; //n, m 변수 선언 n은 tickettable에서 length, m은 caseSIze
	scanf("%d %d", &n, &m);

	vector<int>ids(m); //m size의 ids 벡터 선언
	for (int i = 0; i < m; ++i) {
		scanf("%d", &ids[i]);
	}
	vector<int> tickets = getTicketNumbers(n, m, ids); //getTicketNumbers에서 반환된 tickettable을 ticket 벡터에 저장
	for (int i = 0; i < tickets.size(); ++i) {
		printf("%d\n", tickets[i]);
	}
}
