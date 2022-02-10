#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
typedef tuple<int, string, int> ti;
bool cmp(ti& s1, ti& s2) {
	if (get<0>(s1) != get<0>(s2))
		return get<0>(s1) < get<0>(s2);
	return get<2>(s1) < get<2>(s2);
}
int main() {
	int n, a;
	string b;
	cin >> n;

	vector<ti> arr(n, ti());
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[i] = make_tuple(a, b, i);
	}
	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << get<0>(arr[i]) <<' '<< get<1>(arr[i]) << '\n';
}
