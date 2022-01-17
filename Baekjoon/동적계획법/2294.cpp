#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9;
int solu(int n,int k, vector<int>& coin) {
	vector<int> dp(n+1, INF);

	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; i++)
			if (dp[j - coin[i]] != INF)
				dp[j] = min(dp[j], dp[j-coin[i]]+1);
	if (dp[k] == INF)
		return -1;
	return dp[k];
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coin(n, 0);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cout << solu(n, k, coin);
}
