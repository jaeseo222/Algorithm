#include<iostream>
#include<vector>
using namespace std;
int ans(int n) {
	vector<int> dp(n+1,0);

	// 1,2,3 만드는 데 필요한 횟수 초기화
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 1]+dp[i - 2]+dp[i - 3];

	return dp[n];
}
int main() {
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		cout << ans(n)<<'\n';
	}
}
