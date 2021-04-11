#include <iostream>
#include <vector>
using namespace std;

class TicketTable { //TicketTable Ŭ���� ����
public:
	vector<bool> used; //tickettable���� ������� length���� Ȯ���� ���� bool�� vector ����
	int length;
	TicketTable(int length) { //������
		this->length = length;
		this->used.assign(length, false);
	}

	int findEmptyIndexByUserId(int userId) { //userId�� ���� �� index���� ã�� �޼ҵ�
		int index = userId % length; // index = userId�� length�� ���� ������
		while (this->isEmpty(index) == true) { // ������� �� ���� index = (index + 1) % length
			index = (index + 1) % length;
		}
		return index; 
	}

	bool isEmpty(int ticketIndex) { //����ִ��� Ȯ���ϴ� �޼ҵ�
		return this->used[ticketIndex];
	}
	void setUsed(int index, bool status) { //����ִ� �� Ȯ�� �� �� �ش� �ε����� status�� false���� true�� �ٲ���
		this->used[index] = status;
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) { //Ticketnumber�� ��ȯ�ϴ� �޼ҵ�
	vector<int> tickets; // tickets ���� ����
	TicketTable table = TicketTable(n); //ticketTable ����

	for (int i = 0; i < m; i++) { // �ݺ����� m�� ���� ids������ �̿��Ͽ� table�� ä���
		int userId = ids[i]; //ids�迭���� userid ����
		int ticketIndex = table.findEmptyIndexByUserId(userId); //userid�� ���� ����ִ� index Ȯ��
		tickets.push_back(ticketIndex); //userid�� ã�� ticketindex�� ticket ���Ϳ� push
		table.setUsed(ticketIndex, true); //index�� �ش��ϴ� table�� setused ���·� ����
	}
	return tickets; 
}

int main() {
	int n, m; //n, m ���� ���� n�� tickettable���� length, m�� caseSIze
	scanf("%d %d", &n, &m);

	vector<int>ids(m); //m size�� ids ���� ����
	for (int i = 0; i < m; ++i) {
		scanf("%d", &ids[i]);
	}
	vector<int> tickets = getTicketNumbers(n, m, ids); //getTicketNumbers���� ��ȯ�� tickettable�� ticket ���Ϳ� ����
	for (int i = 0; i < tickets.size(); ++i) {
		printf("%d\n", tickets[i]);
	}
}
