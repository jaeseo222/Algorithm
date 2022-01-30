#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
		cout << binary_search(arr.begin(), arr.end(), tmp)<<'\n';
	}
}
