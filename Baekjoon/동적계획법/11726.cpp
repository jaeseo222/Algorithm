#include<iostream>
#include<vector>
using namespace std;
int squ(int n) {
	vector<int> dp(n+1,0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i =2; i <= n; i++)
			dp[i] = (dp[i - 1]+dp[i - 2]) % 10007;// | : -1, = : -2

	return dp[n];
}
int main() {
	int n;
	cin >> n;

	cout << squ(n);
}
