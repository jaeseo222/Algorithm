#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;

	vector<int> timeArr(n);
	for (int i = 0; i < n; i++)
		cin >> timeArr[i];

	sort(timeArr.begin(), timeArr.end());

	for (int i = 0; i < n-1; i++)
		timeArr[i+1] += timeArr[i];

	for (int i = 0; i < n; i++)
		ans += timeArr[i];
	cout <<ans;
}
