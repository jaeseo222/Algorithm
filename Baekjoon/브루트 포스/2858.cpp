#include<iostream>
using namespace std;
pair<int, int> solu(int r, int b) {
	int area = r + b;

	for (int i = area; i > 0; i--)
		if (area % i == 0) {
			int w = area / i;
			if (r == (i + w) * 2 - 4)
				return make_pair(i, w);
		}
}

int main() {
	int n, m;
	cin >> n >> m;

	pair<int, int> ans = solu(n, m);

	cout << ans.first << " " << ans.second;
}
