#include<iostream>
#include<vector>
using namespace std;
int numOne(int n) {
	vector<int> dp(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

  //
  for (int i = 2; i <= n; i++)
		dp[i] = min(dp[i - 1], min(i % 2 == 0 ? dp[i / 2] : n, i % 3 == 0 ? dp[i / 3] : n)) + 1;
  
	return dp[n];
}
int main() {
	int n;
	cin >> n;

	cout << numOne(n);
}
