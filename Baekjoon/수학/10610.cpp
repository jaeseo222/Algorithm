#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

vector<int> findNum(string num) {
	// 30 배수인지 확인
	vector<int> number(num.size(), 0);
	bool isTen = false;// 0 이 존재하는지
	int sum = 0; // 3 의 배수인지

	for (int i = 0; i < num.size(); i++) {
		number[i] = num[i] - '0';
		sum += number[i];
		if (number[i] == 0)
			isTen = true;
	}
	if (isTen && sum % 3 == 0) return number;
	return { -1 };
}

int main() {
	string num;
	cin >> num;
	vector<int> ans = findNum(num);

	sort(ans.begin(), ans.end(), greater<>()); //가장 큰 수
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
}
