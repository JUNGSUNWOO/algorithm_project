#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//에라토스테네스의 채를 활용한 소수세기
class Sieve { //sieve클래스 선언
public:
	int maximumValue;
	vector<bool> isPrime; //소수판별 벡터 선언
	Sieve(int maximumValue) { //생성자
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false);
		this->fillSieve();
	}

	bool isPrimeNumber(int num) const { //number가 소수인지 반환하는 메소드
		return this->isPrime[num];
	}
	void fillSieve() { //isPrime벡터에 소수를 체크하는 메소드
		isPrime.assign(this->maximumValue, true); // isPrime 벡터를 모두 true로 변경
		isPrime[0] = isPrime[1] = false; //0,1은 false로 초기화 ->소수가아니기때문
		for (int num = 2; num <= maximumValue; num += 1) { //2부터 maxValue까지 반복
			if (isPrime[num] == false) { //false인 벡터는 continue
				//소수가아니라고 체크되어있으면 continue
				continue;
			}

			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) { //long long으로 변수 선언 num*num이 int형을 넘어 갈 수 있기 때문에
				//num*num 부터 maxValue까지 반복
				int index = (int)mul;  //index=mul
				isPrime[index] = false; //num*num 부터 +=num까지 num의 배수이기 때문에 false로 저장 =>소수가아님
			}
		}
	}
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) { //소수를 구하는 벡터
	vector<int> primes; //primes벡터 선언

	for (int num = from; num <= to; num += 1) { //from부터 to까지 반복
		if (sieve.isPrimeNumber(num)) { //sieve클래스의 isPrimeNumber메소드(소수인지 여부 return)
			primes.push_back(num); //소수이면 primes벡터에 push back
		}
	}
	return primes; //return
}

void process(int caseIndex, const Sieve& sieve) { 
	int L, R;
	scanf("%d%d", &L, &R); //L과 R입력
	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve); //L부터 R까지 소수 출력

	printf("Case #%d:\n", caseIndex);
	printf("%d\n", (int)allPrimeNumbers.size()); //소수의 개수 출력(size메소드)
		
}

int main()
{
	const int MAX_VALUE = 1000000; 
	Sieve sieve = Sieve(MAX_VALUE); //Sieve선언 & 초기화

	int caseSize;
	cin >> caseSize; //caseSize 입력

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve); //소수 개수 세기 절차 진행
	}
	return 0;
}