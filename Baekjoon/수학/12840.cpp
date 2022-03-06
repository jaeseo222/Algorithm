#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE = 86400; // 하루 총 시간
void timeInput(int& h, int& m, int& s, int sum) {
	h = sum / 3600;
	m = sum / 60 % 60;
	s = sum % 60;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, h, m, s, c, test;
	cin >> h >> m >> s >> test;//현재 정보
	while (test--) {
		cin >> t;
		int sum = 3600 * h + 60 * m + s; //총 초
		if (t == 1) {
			cin >> c;
			sum += c;
		}
		if (t == 2) {
			cin >> c;
			sum -= c;
			while (sum < 0)
				sum += SIZE;
		}
		sum %= SIZE;
		timeInput(h, m, s, sum);
		if (t == 3)
			cout << h << ' ' << m << ' ' << s << '\n';
	}
}
