#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solu(int n, vector<int>& straw) {
	int ans = -1;

	for (int i = 0; i < n - 2; i++)
		if (straw[i] < straw[i + 1] + straw[i + 2]) {//삼각형 조건에 맞을 시
			ans = straw[i] + straw[i + 1] + straw[i + 2];
			break;
		}
	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<int> straw(n, 0);
	for (int i = 0; i < n; i++)
		cin >> straw[i];

	sort(straw.begin(), straw.end(), greater<>());//내림차순 정렬

	cout << solu(n, straw);
}
