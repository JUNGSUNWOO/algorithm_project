#include <cstdio>
#include <iostream>

using namespace std;

//isInside�Լ��� x,y��ǥ�� R�� �Ÿ� �񱳸� ����
//���� ���ο��ִ����� �Ǻ��Ѵ�
bool isInside(long long x, long long y, long long R)
{
	if (x * x + y * y < R * R) return true; //0,0�� �������� x*x + y*y�� R*R���� �۴ٸ� ���ȿ� �ִ� =>true ��ȯ
	return false; //�ƴϸ� false ��ȯ
}
void testcase(int caseIndex) //1��и鸸�� �ľ��Ͽ� *4���ش�
{
	long long R; //������ ����
	scanf("%lld", &R);
	long long sum = 0; //1��и� �ȿ� ��ǥ������ ī��Ʈ�� sum����
	long long y = R; //y�� R����
	for (long x = 0; x <= R; x++)//0~R�ݺ�
	{
		long long height = 0;//height���� ����
		for (; y >= 0; y--)//y�ʱⰪ�� R~0���� �ݺ�
		{
			if (isInside(x, y, R)) { //x,y�� ���ȿ� �ִٸ�
				height = (y + 1); //height�� y+1���� �� break
				break; //for���� y���� R���� 0���� �������� ������ isInside�Լ����� ó�� true������ ������ �ִ�����̴�
			}
		}
		sum += height; //sum�� height�� �����ش�
	}
	printf("#%d\n", caseIndex);
	printf("%lld\n", sum * 4);//��и��� 4���̹Ƿ� *4
}

int main()
{
	int caseSize;
	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++)
	{
		testcase(caseIndex);
	}

	return 0;
		
}