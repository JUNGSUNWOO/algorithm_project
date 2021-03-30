#include <stdio.h>
#include <iostream>

using namespace std;

//solve 함수
//1. data중 p보다 작거나 같은 값들을 찾아 sum에 더해주며, cnt += 1해준다.
//2. sum과 q를 비교하여 함께 탑승이 가능한지 여부를 출력해준다

void solve(int data[], int n, int p, int q)
{
	int cnt = 0; // 탑승가능한 몸무게의 인원 count를 위한 변수
	int sum = 0; // 탑승가능한 몸무게의 인원들의 무게 합 계산을 위한 변수
	for (int i = 0; i < n; i++) // data의 개수만큼 for문을 돌며 data[i]와 인당 무게제한 p를 비교한다
	{
		if (data[i] <= p) { //p보다 몸무게가 작거나 같은 사람들을 찾는다
			sum += data[i]; // 찾은 사람들의 무게를 합한다
			cnt++; // 총 몇명인지 count 해준다
		}
	}

	//print
	printf("%d %d\n", cnt, sum); //총 인원, 무게 합
	if (sum > q) printf("no"); //같이 탑승 가능한지 여부
	else printf("yes");
}

int main()
{
	int n, p, q; //n = 최대 인원수, p = 1인 최대 무게, q = 탑승인원 최대무게
	int* data; //각 인원별 무게 데이터

	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	solve(data, n, p, q);

	delete[] data;
	return 0;
}