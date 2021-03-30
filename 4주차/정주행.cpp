#include <cstdio>
#include <iostream>

using namespace std;

bool isConsecutive(int data[], int n) //연속적인 수열로 표현할 수 있는지 판단하는 함수
{//data배열에서 최대값과 최소값을 구한 뒤
	//최대값 - 최솟값이 배열 size -1과 일치한다면
	//연속적인 수열을 이룬다고 할 수 있다
	int max_data = data[0]; //최대값 변수 선언 및 초기화
	int min_data = data[0]; //최소값 변수 선언 및 초기화
	for (int i = 1; i < n; i++) //1~n까지 반복
	{
		if (max_data < data[i]) max_data = data[i]; //max 값 구하기
		if (min_data > data[i]) min_data = data[i]; //min 값 구하기
	}
	if (max_data - min_data == n - 1) return true; //max-min이 배열size-1과 같다면 true
	return false;//아니면 false
}
int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	bool result = isConsecutive(data, n);

	if (result) printf("Yes");
	else printf("No");

	delete[] data;
	return 0;
}