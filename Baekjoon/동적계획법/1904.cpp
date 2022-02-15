#include<iostream>
using namespace std;
const int SIZE = 15746;
int dp[1000001];
typedef long long ll;
int solu(int n) {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % SIZE;

	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout<< solu(n);
}
