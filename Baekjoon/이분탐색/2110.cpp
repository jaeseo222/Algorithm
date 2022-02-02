#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binaryFun(int left, int right, int m, vector<int>& arr) {
	while (left <= right) {
		int mid = (left + right) / 2; // 존재할 수 있는 간격의 값

		int idx = 0, num = 1;
		for (int i = 1; i < arr.size(); i++) {
			int inter = arr[i] - arr[idx];
			if (inter >= mid) {
				idx = i;
				num++;
			}
		}
		if (num >= m)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	cout << binaryFun(0, arr[n - 1], m, arr);
}
