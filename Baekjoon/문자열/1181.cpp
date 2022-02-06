#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool cmp(string& s1, string& s2) {
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	return s1 < s2;
}

int main() {
	int n;
	string str;
	cin >> n;

	vector<string> arr;
	while (n--) {
		cin >> str;
		if (find(arr.begin(), arr.end(), str) == arr.end()) // 중복 거르기
			arr.push_back(str);
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << '\n';
}
