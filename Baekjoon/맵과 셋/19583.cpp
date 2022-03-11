#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {
	string s,e,q,tmp, name;
	cin >> s >> e >> q;

	int result = 0;
	map<string, bool> info;
	while (cin >> tmp >> name) {
		if (tmp <= s) // 입장시간
			info[name] = true;
		else if (e <= tmp && tmp <= q) //퇴장
			if (info[name]) {
				result++;
				info[name] = false; // 한 사람이 여러 번 채팅 친 거
			}
	}
	cout << result;
}
