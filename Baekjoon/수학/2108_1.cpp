#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci& m1, const ci& m2) {
	if (m1.second != m2.second)
		return m1.second > m2.second;
	return m1.first < m2.first;
}

int findNum(vector<int> & num) {
	map<int, int> tmp;

	for (int i = 0; i < num.size(); i++)
		tmp[num[i]]++;

	vector<ci> ans(tmp.begin(), tmp.end());
	sort(ans.begin(), ans.end(), cmp);

	if (ans[0].second == ans[1].second) //여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
		return ans[1].first;
	return ans[0].first;
}

int main() {
	int n;
	cin >> n;

	vector<int> num(n);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}

	sort(num.begin(), num.end());
	cout << (int)round(sum / n) << '\n';
	cout << num[n / 2] << '\n';
	cout << findNum(num)<<'\n';
	cout << num[n - 1] - num[0];
}
