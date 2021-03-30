#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Point2D { //õĪ�� ��ǥ�� ���� pointŬ����
private:
	int x; //x��ǥ
	int y; //y��ǥ
public:
	Point2D(int x = 0, int y = 0) //������
	{
		this->x = x;
		this->y = y;
	}
	int getSqauredDistanceTo(const Point2D& target) const { //point 1�� ��ǥ���� 2�� ��ǥ������ �Ÿ��� ����
		return pow((this->x - target.x),2) + pow((this->y - target.y),2);
	}

	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSqauredDistanceTo(target); //getSquaredDistanceTo�Լ����� return�� ���� double������ ����ȯ
		return sqrt(sqd); //sqd�� ������ return
	}
};

int main()
{
	int n;
	Point2D* points; //point��ü �迭 ����
	
	scanf("%d", &n);
	points = new Point2D[n]; //���� �Ҵ�

	for (int i = 0; i < n; i++) //n��ŭ �ݺ� point�迭�� �Է�
	{
		int x, y;
		scanf("%d %d", &x, &y);

		points[i] = Point2D(x, y);
	}
	
	int min_sqd = INT_MAX; //�ּҰŸ� ���� ����
	int min_cnt = 0; //�ּҰŸ� ��ǥ�鿡 ��ġ�� õĪ���� count�� ��������

	for (int i = 0; i < n; i++) //for 0-n���� �ݺ�
	{
		for (int j = 0; j < i; j++) //for 0-i���� �ݺ�
		{
			int sqd = points[i].getSqauredDistanceTo(points[j]);//i��ǥ�� j��ǥ���� ��
			if (sqd < min_sqd) { //sqd�� min_sqd���� �۴ٸ� min_sqd�� sqd ���� //min_cnt 1�� �ʱ�ȭ
				min_sqd = sqd;
				min_cnt = 1;
			} 
			else if (sqd == min_sqd) { //sqd�� min_sqd�� ���ٸ� min_cnt +=1
				min_cnt++;
			}
		}
	}

	double distance = sqrt(min_sqd); //distance�� min_sqd�� ������ ����
	printf("%.1f\n", distance);
	printf("%d\n", min_cnt);

	delete[] points; //�����Ҵ� ����
	return 0;
}
