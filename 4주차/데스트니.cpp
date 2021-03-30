#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Point2D { //천칭의 좌표를 받을 point클래스
private:
	int x; //x좌표
	int y; //y좌표
public:
	Point2D(int x = 0, int y = 0) //생성자
	{
		this->x = x;
		this->y = y;
	}
	int getSqauredDistanceTo(const Point2D& target) const { //point 1의 좌표에서 2의 좌표까지의 거리의 제곱
		return pow((this->x - target.x),2) + pow((this->y - target.y),2);
	}

	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSqauredDistanceTo(target); //getSquaredDistanceTo함수에서 return된 값을 double형으로 형변환
		return sqrt(sqd); //sqd의 제곱근 return
	}
};

int main()
{
	int n;
	Point2D* points; //point객체 배열 생성
	
	scanf("%d", &n);
	points = new Point2D[n]; //동적 할당

	for (int i = 0; i < n; i++) //n만큼 반복 point배열에 입력
	{
		int x, y;
		scanf("%d %d", &x, &y);

		points[i] = Point2D(x, y);
	}
	
	int min_sqd = INT_MAX; //최소거리 변수 선언
	int min_cnt = 0; //최소거리 좌표들에 걸치는 천칭들을 count할 변수선언

	for (int i = 0; i < n; i++) //for 0-n까지 반복
	{
		for (int j = 0; j < i; j++) //for 0-i까지 반복
		{
			int sqd = points[i].getSqauredDistanceTo(points[j]);//i좌표와 j좌표들을 비교
			if (sqd < min_sqd) { //sqd가 min_sqd보다 작다면 min_sqd에 sqd 저장 //min_cnt 1로 초기화
				min_sqd = sqd;
				min_cnt = 1;
			} 
			else if (sqd == min_sqd) { //sqd와 min_sqd가 같다면 min_cnt +=1
				min_cnt++;
			}
		}
	}

	double distance = sqrt(min_sqd); //distance에 min_sqd의 제곱근 저장
	printf("%.1f\n", distance);
	printf("%d\n", min_cnt);

	delete[] points; //동적할당 해제
	return 0;
}
