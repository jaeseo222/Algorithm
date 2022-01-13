#include<iostream>
#include<vector>
using namespace std;
int ans;

void solu(int n, vector<pair<int, int>>&con, int start, int sum) {
	if (start > n)
		return;

	ans = max(ans, sum);

	for (int i = start; i < n; i++)
		solu(n, con, i+con[i].first, sum+con[i].second);
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> con(n);//시간, 수익
	for (int i = 0; i < n; i++)
		cin >> con[i].first >> con[i].second;

	solu(n, con, 0,0);

	cout << ans;
}
