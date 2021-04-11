#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//�����佺�׳׽��� ä�� Ȱ���� �Ҽ�����
class Sieve { //sieveŬ���� ����
public:
	int maximumValue;
	vector<bool> isPrime; //�Ҽ��Ǻ� ���� ����
	Sieve(int maximumValue) { //������
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false);
		this->fillSieve();
	}

	bool isPrimeNumber(int num) const { //number�� �Ҽ����� ��ȯ�ϴ� �޼ҵ�
		return this->isPrime[num];
	}
	void fillSieve() { //isPrime���Ϳ� �Ҽ��� üũ�ϴ� �޼ҵ�
		isPrime.assign(this->maximumValue, true); // isPrime ���͸� ��� true�� ����
		isPrime[0] = isPrime[1] = false; //0,1�� false�� �ʱ�ȭ ->�Ҽ����ƴϱ⶧��
		for (int num = 2; num <= maximumValue; num += 1) { //2���� maxValue���� �ݺ�
			if (isPrime[num] == false) { //false�� ���ʹ� continue
				//�Ҽ����ƴ϶�� üũ�Ǿ������� continue
				continue;
			}

			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) { //long long���� ���� ���� num*num�� int���� �Ѿ� �� �� �ֱ� ������
				//num*num ���� maxValue���� �ݺ�
				int index = (int)mul;  //index=mul
				isPrime[index] = false; //num*num ���� +=num���� num�� ����̱� ������ false�� ���� =>�Ҽ����ƴ�
			}
		}
	}
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) { //�Ҽ��� ���ϴ� ����
	vector<int> primes; //primes���� ����

	for (int num = from; num <= to; num += 1) { //from���� to���� �ݺ�
		if (sieve.isPrimeNumber(num)) { //sieveŬ������ isPrimeNumber�޼ҵ�(�Ҽ����� ���� return)
			primes.push_back(num); //�Ҽ��̸� primes���Ϳ� push back
		}
	}
	return primes; //return
}

void process(int caseIndex, const Sieve& sieve) { 
	int L, R;
	scanf("%d%d", &L, &R); //L�� R�Է�
	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve); //L���� R���� �Ҽ� ���

	printf("Case #%d:\n", caseIndex);
	printf("%d\n", (int)allPrimeNumbers.size()); //�Ҽ��� ���� ���(size�޼ҵ�)
		
}

int main()
{
	const int MAX_VALUE = 1000000; 
	Sieve sieve = Sieve(MAX_VALUE); //Sieve���� & �ʱ�ȭ

	int caseSize;
	cin >> caseSize; //caseSize �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve); //�Ҽ� ���� ���� ���� ����
	}
	return 0;
}