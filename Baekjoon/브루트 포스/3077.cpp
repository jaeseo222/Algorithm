#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

string solu(int n, map<string, int>& arr, vector<string>& que) {
	int ans = 0, total = n * (n - 1) / 2;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[que[i]] < arr[que[j]]) // ex. (0->sacheon->1) < (2->myeongnyang->3)
				ans++;
	return to_string(ans) + "/" + to_string(total);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string input;

	cin >> n;
	map<string, int> ans;
	vector<string> que(n);

	for (int i = 0; i < n; i++) {
		cin >> input;
		ans[input] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> que[i];
	cout << solu(n, ans, que);
}
