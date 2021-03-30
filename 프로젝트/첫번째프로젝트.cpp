#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;

int getUserScore(string user, string* fri, int cnt, int round); //�Է¹��� user�� score�� ����ϴ� �޼ҵ�
int getMaxScore(string* fri, int round, int cnt); //ģ������ data�� �����ϴ� user�� ���� �� �ִ� �ִ밪�� ����ϴ� �޼ҵ�
int findmax(int* rsp_cnt); // getMaxScore���� ���� rsp_cnt�� max���� return�ϴ� �޼ҵ�

int main()
{
	int round; //round ���� ����
	string user_rsp; //user�� data�� �޾ƿ� string ���� ����
	int fri; //friend �� ���� ����
	string* fri_rsp; //friend���� data�� �޾ƿ� string ������ ����

	cin >> round; //round input
	cin >> user_rsp; //user data input

	cin >> fri; //friend number input
	fri_rsp = new string[fri]; //friend �迭 �����Ҵ�
	for (int i = 0; i < fri; i++) //friend data input
	{
		cin >> fri_rsp[i];
	}
	//clock_t start = clock(); //clock start 
	int user_score = 0; //USER SCORE, MAX_SCORE ���� ����
	int max_score = 0;
	
	user_score = getUserScore(user_rsp, fri_rsp, fri, round);//getUserScore���� return user score 
	max_score = getMaxScore(fri_rsp, round, fri); // getMaxScore���� return max score


	printf("%d\n", user_score); // user���� ���
	printf("%d\n", max_score); //�ִ����� ���

	delete[] fri_rsp; //�����Ҵ� ����
	//clock_t end = clock(); //clock end

	//printf("����ð� : %.12lf��\n", (double)(end - start) / clocks_per_sec); //����ð� ���

	return 0;
}

int getUserScore(string user, string* fri, int cnt, int round)
{
	int score = 0; //score�� ������ ���� ����

	for (int i = 0; i < cnt; i++) //�ݺ��� friend ����ŭ
	{
		for (int j = 0; j < round; j++) //�ݺ��� round ��ŭ
		{
			//			cout << user[j] << " " << fri[i][j] << "\n";
			if (user[j] == 'R') //user�� �ָ��� ��
			{
				if (fri[i][j] == 'S') score += 2; //friend�� �����̸� +2
				else if (fri[i][j] == 'R') score += 1; //friend�� �ָ��̸� +1
				else if (fri[i][j] == 'P') score += 0; //friend�� ���ڱ�� +0
			}
			if (user[j] == 'S')//user�� ������ ��
			{
				if (fri[i][j] == 'P') score += 2; //friend�� ���ڱ�� +2
				else if (fri[i][j] == 'S') score += 1;//friend�� �����̸� +1
				else if (fri[i][j] == 'R') score += 0;//friend�� �ָ��̸� +0
			}
			if (user[j] == 'P')//user�� ���ڱ��� ��
			{
				if (fri[i][j] == 'R') score += 2;//friend�� �ָ��̸� +2
				else if (fri[i][j] == 'P') score += 1;//friend�� ���ڱ�� +1
				else if (fri[i][j] == 'S') score += 0;//friend�� �����̸� +0
			}
		}
	}
	return score;//return score
}

int getMaxScore(string* fri, int round, int cnt)
{
	int score = 0; //score�� ������ ���� ����
	for (int i = 0; i < round; i++) { // round��ŭ �ݺ�
		int rsp_cnt[3] = { 0,0,0 }; 
		//���� ���� ģ������ R,S,P�� ���� �������� ������ ���� ����
		/*
		ģ������ �� ���帶�� rsp�����͵��� ���� 
		ģ�� 1�� R�̸� => ���ڱ� += 2, �ָ� += 1
		ģ�� 2�� S�ӳ� => �ָ� +=2, ���� += 1
		ģ�� 3�� S�̸� => �ָ� +=2, ���� += 1
		�̹Ƿ� ���� findmax���� �ָ��� ���� ���� ���� 5�� return �մϴ�.
		*/
		for (int j = 0; j < cnt; j++) { //friend�� ��ŭ �ݺ�
			if (fri[j][i] == 'R') //friend�� R�̸�
			{
				rsp_cnt[2]+= 2; //���ڱ� += 2
				rsp_cnt[0] += 1;//�ָ� += 1
			}
			else if (fri[j][i] == 'S') //friend�� S�̸�
			{
				rsp_cnt[0]+=2; //�ָ� +=2
				rsp_cnt[1]++; // ���� ++
			}
			else if (fri[j][i] == 'P')//friend�� P�̸�
			{
				rsp_cnt[1]+=2; //���� +=2
				rsp_cnt[2]++; //���ڱ�++
			}
		}
		score += findmax(rsp_cnt); //�� ���� ģ������ ���� R,S,P������ ������ ������ findmax�Լ��� �����ش�
	}
	return score;
}

int findmax(int* rsp_cnt) {
	int max = 0; //max���� ������ ���� ����
	for (int i = 0; i < 3; i++)
	{
		if (max < rsp_cnt[i]) max = rsp_cnt[i]; 
	}
	return max; //rsp_cnt�迭���� max�� return
}

