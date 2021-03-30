#include <cstdio>
#include <iostream>

using namespace std;

/*height �Է�, month�Է� ����
* month�� m�� ���Ͽ� index ��ġ�� �޾ƿ´�. in ���ο� �迭
* month�� ���ٸ� return -1
* height index��ġ�� ���Ͽ� ���� ū height return 
*/
int getMaximumHeight(int height[], int month[], int n, int m)
{
	int cnt = 0; //�ش��ϴ� month�� ������ ī��Ʈ �ϱ����� ����
	int* tmp; // �ش��ϴ� month�� ������ �迭 tmp
	tmp = new int[n]; 
	for (int i = 0; i < n; i++) //�ݺ��� ���� month�迭�� m�� ��ġ�ϴ� index�� tmp�� �����ϰ� ���� cnt�� ����
	{
		if (month[i] == m)
		{
			tmp[cnt] = i;
			cnt++;
		}
	}
	if (cnt == 0) return -1; //cnt �� 0�̸� return -1
	else//cnt�� 0�� �ƴϸ�
	{
		int max = 0;//max ���� ����
		for (int i = 0; i < cnt; i++) //�ݺ��� cnt�� ���鼭 max���� ã�´�
		{
			if (max < height[tmp[i]])
			{
				max = height[tmp[i]];
			}
		}
		return max;
	}
}

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &height[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m);

	int answer = getMaximumHeight(height, month, n, m);

	printf("%d\n", answer);
	
	delete[] height;
	delete[] month;
	return 0;
}