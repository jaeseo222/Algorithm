#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, string> ci;
bool cmp(ci s1, ci s2) {
	return s1.first < s2.first;
}
int main() {
	int n;
	cin >> n;

	vector<ci> arr(n, ci());
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	stable_sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << ' ' << arr[i].second << '\n';
}
