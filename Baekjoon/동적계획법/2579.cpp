#include<iostream>
#include<vector>
using namespace std;

int solu(int n, vector<int> &score) {
	vector<int> dp(n+1);

	dp[1] = score[1];
	dp[2] = score[1]+score[2];
	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i-2], dp[i-3]+score[i-1])+score[i];

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	vector<int> score(n+1);
	for (int i = 1; i <= n; i++)
		cin >> score[i];

	cout << solu(n, score);
}
