#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lowerBound(int left, int right, int tar, vector<int>& card) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (card[mid] >= tar)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right + 1;
}
int upperBound(int left, int right, int tar, vector<int>& card) {
	while (left <= right) {
		int mid = (left + right) / 2;

		if (card[mid] <= tar)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right + 1;
}

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
		cout << upperBound(0, n - 1, t, card) - lowerBound(0, n - 1, t, card) << ' ';
	}
}
