#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binaryFun(int left, int right, int m, vector<int>& arr) {
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		int num = 0;
		for (int i = 0; i < arr.size(); i++)
			num += min(arr[i], mid);

		if (num <= m) {
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	cin >> m;

	cout << binaryFun(0, arr[n - 1], m, arr);
}
