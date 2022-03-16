#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 26;

vector<int> countAlph(string name) {
	vector<int> cnt(SIZE);

	for (int i = 0; i < name.size(); i++)
		cnt[name[i] - 'A']++;

	return cnt;
}
string prt(vector<int> cnt) {
	// 왼쪽, 가운데, 오른쪽
	string str1 = "", str2="", str3="";

	for (int i = 0; i < SIZE; i++) {
		// 알파벳의 개수가 홀수면 가운데에 놔줘야함
		if (cnt[i] % 2 == 1) {
			// 이미 가운데 차지하고 있으면 못 만듦.
			if (str2 != "") return "I'm Sorry Hansoo";
			str2 = (char)(i + 'A');
		}
		for (int j = 0; j < cnt[i] / 2; j++) {
			str1 += (char)(i + 'A');
			str3 = (char)(i + 'A') + str3; // 거꾸로 붙이기
		}
	}
	return str1 + str2 + str3;
}
int main() {
	string name;
	cin >> name;

	vector<int> cnt = countAlph(name);
	cout << prt(cnt);
}
