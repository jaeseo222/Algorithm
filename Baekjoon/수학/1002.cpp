#include<iostream>
#include<cmath>
using namespace std;
int solu(int d, int sum, int rem) {
	if (rem<d&&d<sum)
		return 2;
	if (sum==d||rem==d)
		return 1;
	return 0;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = pow((x1 - x2),2) + pow((y1 - y2),2);
		int sum = pow((r1 + r2),2);
		int rem = pow((r1 - r2),2);
		if (d == 0)
			if (rem == 0)
				cout << -1;
			else
				cout << 0;
		else
			cout << solu(d, sum, rem);
		cout << '\n';
	}
}
