#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int SIZE = 1e6;
int solu(string num, int n) {
	int ans = 0;

	if (num[0] == '0') return 0;

	vector<int> dp(n + 1);
	dp[0] = dp[1] = 1; // 초기화

	for (int i = 2; i <= n; i++) { // dp의 index
		int idx = i - 1; // num의 index
		if (num[idx] == '0' && (num[idx - 1] < '1' || num[idx - 1] > '2')) return 0; // 30, 00 ...

		if (num[idx] != '0') // 8, 3 ... 한 자리수
			dp[i] += dp[i - 1];
		if ((num[idx - 1] == '1') || (num[idx - 1] == '2' && num[idx] <= '6')) // 10, 20, 18 ... 두 
			dp[i] += dp[i - 2];

		dp[i] %= SIZE;
	}
	ans = dp[n];
	return ans;
}

int main() {
	string num;
	cin >> num;
	cout << solu(num, num.length());
}
