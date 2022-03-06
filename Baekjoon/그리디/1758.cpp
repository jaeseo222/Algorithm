#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	ll n, sum = 0;
	cin >> n;

	vector<ll> guest(n);
	for (ll i = 0; i < n; i++)
		cin >> guest[i];
	sort(guest.begin(), guest.end(), greater<>());//내림차순으로 해서
	//많이 받을 수 있는 건 많이 받아놓기

	for (ll i = 0; i < n; i++)
		if (guest[i] - i > 0) //원래 주려고 생각했던 돈 - (받은 등수 - 1) > 0 일때
			sum += guest[i] - i;
	cout << sum;
}
