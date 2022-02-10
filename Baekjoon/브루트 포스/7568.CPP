#include<iostream>
#include<vector>
using namespace std;
vector<int> solu(int n, vector<pair<int, int>>& arr) {
	vector<int> ans(n, 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				ans[i]++;

	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n, pair<int, int>());
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	vector<int> ans = solu(n, arr);

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}
