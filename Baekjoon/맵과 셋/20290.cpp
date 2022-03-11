#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<string, int> ci;
bool cmp(const ci& s1, const ci& s2) {
	if (s1.second != s2.second)
		return s1.second > s2.second;
	if (s1.first.size() != s2.first.size())
		return s1.first.size() > s2.first.size();
	return s1.first < s2.first;
}

int main() {
	int n, m;
	string str;
	cin >> n >> m;

	map<string, int> word;
	while (n--) {
		cin >> str;
		if (str.size() < m) continue;

		word[str]++; // 나온 횟수
	}
	vector<ci> voca(word.begin(), word.end()); // 받은 정보는 중복x, 정렬됨.
	sort(voca.begin(), voca.end(), cmp);

	for (auto iter : voca)
		cout << iter.first << '\n';
}
