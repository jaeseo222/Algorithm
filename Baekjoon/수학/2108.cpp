#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <numeric>
using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci& t1, const ci& t2) {
	if (t1.second == t2.second)
		return t1.first < t2.first;
	return t1.second > t2.second;
}
int presentNum(vector<int>& num) {
	vector<ci> tmp; // 숫자, 개수

	tmp.push_back({ num[0],1 });
	int idx = 0; // tmp 의 인덱스
	for (int i = 1; i < num.size(); i++) {
		if (num[i] == num[i - 1])
			tmp[idx].second++;
		else {
			tmp.push_back({ num[i],1 });
			idx++;
		}
	}

	// 한 종류만 들어왔을 경우
	if (idx == 0) return tmp[0].first;

	sort(tmp.begin(), tmp.end(), cmp); // 알파벳은 오름차순, 개수는 내림차순

	if (tmp[0].second == tmp[1].second)
		return tmp[1].first; // 여러 개 있으면 두 번째로 작은 값

	return tmp[0].first;
}

int main() {
	int n;
	//float sum = 0.0; // float로 계산
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		//sum += num[i];
	}

	sort(num.begin(), num.end());
	float sum = accumulate(num.begin(), num.end(), 0);

	cout << floor(sum / n + 0.5) << '\n'; // 산술평균
	cout << num[n / 2] << '\n'; // 중앙값
	cout << presentNum(num) << '\n'; // 최빈값
	cout << num[n - 1] - num[0] << '\n'; // 범위
}
