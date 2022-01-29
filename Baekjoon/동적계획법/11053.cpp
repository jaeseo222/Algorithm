#include<iostream>
#include<vector>
using namespace std;
int leng(int n, vector<int>& arr) {
	vector<int> dp(n + 1, 0);

	int maxi = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j]+1);
		maxi = max(maxi, dp[i]); // 가장 긴 길이 저장
	}
	return maxi;
}
int main() {
	int n;
	cin >> n;

	vector<int> arr(n+1, 0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cout << leng(n, arr);
}
