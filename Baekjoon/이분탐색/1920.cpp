#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool binarySe(int left, int right, int target, vector<int> & arr) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] == target)
			return true;
		if (arr[mid] > target)
			right = mid - 1;
		if (arr[mid] < target)
			left = mid + 1;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, tmp;

	cin >> n;
	vector<int> arr(n,0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	cin >> m;
	while (m--) {
		cin >> tmp;
		cout << binarySe(0, n-1, tmp, arr)<<'\n';
	}
}
