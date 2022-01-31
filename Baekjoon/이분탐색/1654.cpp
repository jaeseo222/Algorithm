#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll binaryFun(ll left, ll right, ll n, vector<ll>& arr) {
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;

		ll num = 0;
		for (ll i = 0; i < arr.size(); i++)
			if (arr[i] / mid) //나눠지는 지 확인(생략 가능)
				num += arr[i] / mid;
		if (num >= n) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

int main() {
	ll k, n;

	cin >> k >> n;
	vector<ll> arr(k, 0);
	for (ll i = 0; i < k; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	cout << binaryFun(1, arr[k - 1], n, arr); //길이는 1부터 시작하니까
}
