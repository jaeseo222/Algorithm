#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t;
	cin >> n;

	vector<int> card(n, 0);
	for (int i = 0; i < n; i++)
		cin >> card[i];

	sort(card.begin(), card.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		cout << binary_search(card.begin(), card.end(), t) << ' ';
	}
}
