#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

/*앨범의 다양성을 구하는 문제이다.
중복구조가 없는 set(집합)구조를 사용하여 배열을 set으로 변환해준다.
set의 size를 구하면 다양성을 return할 수 있다.*/
int getElementTypeCount(int data[], int n)
{

	set<int> s(data, data+n); //data array를 set으로 변환
	int countType = s.size(); // countType 변수를 선언 후 set.size로 초기화
	return countType; // return
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
	int answer = getElementTypeCount(data, n);

	printf("%d\n", answer);

	delete[] data;
	return 0;

}