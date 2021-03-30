#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;

int getUserScore(string user, string* fri, int cnt, int round); //입력받은 user의 score를 계산하는 메소드
int getMaxScore(string* fri, int round, int cnt); //친구들의 data로 추정하는 user가 얻을 수 있는 최대값을 계산하는 메소드
int findmax(int* rsp_cnt); // getMaxScore에서 나온 rsp_cnt중 max값을 return하는 메소드

int main()
{
	int round; //round 변수 선언
	string user_rsp; //user의 data를 받아올 string 변수 선언
	int fri; //friend 수 변수 선언
	string* fri_rsp; //friend들의 data를 받아올 string 포인터 선언

	cin >> round; //round input
	cin >> user_rsp; //user data input

	cin >> fri; //friend number input
	fri_rsp = new string[fri]; //friend 배열 동적할당
	for (int i = 0; i < fri; i++) //friend data input
	{
		cin >> fri_rsp[i];
	}
	//clock_t start = clock(); //clock start 
	int user_score = 0; //USER SCORE, MAX_SCORE 변수 선언
	int max_score = 0;
	
	user_score = getUserScore(user_rsp, fri_rsp, fri, round);//getUserScore에서 return user score 
	max_score = getMaxScore(fri_rsp, round, fri); // getMaxScore에서 return max score


	printf("%d\n", user_score); // user점수 출력
	printf("%d\n", max_score); //최대점수 출력

	delete[] fri_rsp; //동적할당 해제
	//clock_t end = clock(); //clock end

	//printf("실행시간 : %.12lf초\n", (double)(end - start) / clocks_per_sec); //실행시간 출력

	return 0;
}

int getUserScore(string user, string* fri, int cnt, int round)
{
	int score = 0; //score를 저장할 변수 선언

	for (int i = 0; i < cnt; i++) //반복문 friend 수만큼
	{
		for (int j = 0; j < round; j++) //반복문 round 만큼
		{
			//			cout << user[j] << " " << fri[i][j] << "\n";
			if (user[j] == 'R') //user가 주먹일 때
			{
				if (fri[i][j] == 'S') score += 2; //friend가 가위이면 +2
				else if (fri[i][j] == 'R') score += 1; //friend가 주먹이면 +1
				else if (fri[i][j] == 'P') score += 0; //friend가 보자기면 +0
			}
			if (user[j] == 'S')//user가 가위일 때
			{
				if (fri[i][j] == 'P') score += 2; //friend가 보자기면 +2
				else if (fri[i][j] == 'S') score += 1;//friend가 가위이면 +1
				else if (fri[i][j] == 'R') score += 0;//friend가 주먹이면 +0
			}
			if (user[j] == 'P')//user가 보자기일 때
			{
				if (fri[i][j] == 'R') score += 2;//friend가 주먹이면 +2
				else if (fri[i][j] == 'P') score += 1;//friend가 보자기면 +1
				else if (fri[i][j] == 'S') score += 0;//friend가 가위이면 +0
			}
		}
	}
	return score;//return score
}

int getMaxScore(string* fri, int round, int cnt)
{
	int score = 0; //score를 저장할 변수 선언
	for (int i = 0; i < round; i++) { // round만큼 반복
		int rsp_cnt[3] = { 0,0,0 }; 
		//라운드 마다 친구들의 R,S,P에 따른 점수들을 저장할 변수 선언
		/*
		친구들의 각 라운드마다 rsp데이터들을 돌며 
		친구 1이 R이면 => 보자기 += 2, 주먹 += 1
		친구 2가 S임녀 => 주먹 +=2, 가위 += 1
		친구 3이 S이면 => 주먹 +=2, 가위 += 1
		이므로 최종 findmax에서 주먹을 냈을 때의 점수 5를 return 합니다.
		*/
		for (int j = 0; j < cnt; j++) { //friend수 만큼 반복
			if (fri[j][i] == 'R') //friend가 R이면
			{
				rsp_cnt[2]+= 2; //보자기 += 2
				rsp_cnt[0] += 1;//주먹 += 1
			}
			else if (fri[j][i] == 'S') //friend가 S이면
			{
				rsp_cnt[0]+=2; //주먹 +=2
				rsp_cnt[1]++; // 가위 ++
			}
			else if (fri[j][i] == 'P')//friend가 P이면
			{
				rsp_cnt[1]+=2; //가위 +=2
				rsp_cnt[2]++; //보자기++
			}
		}
		score += findmax(rsp_cnt); //한 라운드 친구들의 종합 R,S,P데이터 누적이 끝나면 findmax함수로 보내준다
	}
	return score;
}

int findmax(int* rsp_cnt) {
	int max = 0; //max값을 저장할 변수 선언
	for (int i = 0; i < 3; i++)
	{
		if (max < rsp_cnt[i]) max = rsp_cnt[i]; 
	}
	return max; //rsp_cnt배열에서 max값 return
}

