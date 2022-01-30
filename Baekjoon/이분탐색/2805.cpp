#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll  binarySearch(ll left, ll right, ll height, vector<ll>& tree) {
	ll maxH = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;

		ll num = 0;
		for (ll i = 0; i < tree.size(); i++)
			if (tree[i] > mid) //자를 수 있는 지 확인
				num += (tree[i] - mid);

		if (num >= height) {
			maxH = max(maxH, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return maxH;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;

	cin >> n >> m;
	vector<ll> tree(n, 0);
	for (ll i = 0; i < n; i++)
		cin >> tree[i];

	sort(tree.begin(), tree.end());

	cout << binarySearch(0, tree[n - 1], m, tree) << '\n';
}
