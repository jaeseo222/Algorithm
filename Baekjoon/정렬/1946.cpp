#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;

int solu(vector<ci>& arr, int n) {
	int ans = 1, rank = arr[0].second; // 서류 1등은 합격, 

	for (int i = 1; i < n; i++) {
		if (rank > arr[i].second)
			ans++;
		rank = min(rank, arr[i].second); // 등수를 최솟값으로 갱신해가면서 비교
	}
	return ans;
}

int main() {
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		vector<ci> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end()); // 우선 내림차순으로 서류면접 순위 결정

		cout << solu(arr, n) << '\n';
	}
}
