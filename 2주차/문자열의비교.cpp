#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 100000;

class MyString {
private:
	char* characters;
	int length;
public:
	MyString(const char* str)
	{
		this->length = strnlen(str, MAX_LENGTH);
		this->characters = new char[this->length];
		for (int i = 0; i < this->length; i++)
		{
			this->characters[i] = str[i];
		}
	}
	MyString(const string & original)
	{
		this->length = original.length();
		this->characters = new char[this->length];
		for (int i = 0; i < this->length; i++)
		{
			this->characters[i] = original[i];
		}
	}
	~MyString()
	{
		delete[] characters;
	}

	bool operator < (const MyString& o) const {
		int n = min(this->length, o.length);
		for (int i = 0; i < n; i++) {
			if (this->characters[i] < o.characters[i]) {
				return true;
			}
			else if (this->characters[i] > o.characters[i]) {
				return false;
			}
		} // this가 사전순으로 앞이면 true 출력
		if (this->length < o.length) {
			return true;
		}
		else {
			return false;
		} // this 길이가 짧은 경우 true출력
	}

	bool operator > (const MyString& o) const {
		int n = min(this->length, o.length);
		for (int i = 0; i < n; i++) {
			if (this->characters[i] < o.characters[i]) {
				return false;
			}
			else if (this->characters[i] > o.characters[i]) {
				return true;
			}
		} // this가 사전순으로 앞이면 true 출력
		if (this->length <= o.length) {
			return false;
		}
		else {
			return true;
		} // this 길이가 짧은 경우 true출력
	}

	bool operator == (const MyString& o) const {
		if (this->length != o.length) {
			return false;
		}// 길이가 다른 경우 false출력
		printf("%d %d", this->length, o.length);
		for (int i = 0; i < this->length; i++) {
			if (this->characters[i] != o.characters[i]) {
				return false;
			}
		}
		return true;
		// this와 o가 다른 경우 false출력
	}
};

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;

	MyString mys1(s1);
	MyString mys2(s2);

	if (mys1 < mys2)
	{
		printf("-1");
	}
	else if (mys1 > mys2)
	{
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}