#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pi;

bool cmp(const pi& i1, const pi& i2) { // 없어도 됨.
	return i1.first < i2.first;
}

int ans(vector<pi> arr) {
	int sum=1, tmp = arr[0].second; // 최솟값으로 갱신해가면서 비교
	for (int i = 1; i < arr.size(); i++)
		if (tmp > arr[i].second) {
			tmp = arr[i].second;
			sum++;
		}
	return sum;
}

int main() {
	int t, n;
	cin >> t;

	while(t--) {
		cin >> n;
		vector<pi> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end(),cmp);
		cout << ans(arr) << '\n';
	}
}
