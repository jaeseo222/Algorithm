#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll solu(int n, vector<int>& exam, int b, int c) {
	ll ans = n; // 총감독관 미리 배치

	for (int i = 0; i < n; i++) {
		int cnt = exam[i] - b;

		if (cnt <= 0) continue;

		// 부감독관
		ans += cnt / c;
		
		// 감독할 사람 남은 경우
		if (cnt % c > 0)
			ans++;
	}
	return ans;
}

int main() {
	int n, b, c;

	cin >> n;
	vector<int> exam(n);
	for (int i = 0; i < n; i++)
		cin >> exam[i];
	cin >> b >> c;

	cout << solu(n, exam, b, c);
}
