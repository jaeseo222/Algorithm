#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calcTime(vector<int>&withdraw, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += withdraw[i] * (n-i);
	return sum;
}

int main() {
	int n;
	cin >> n;

	vector<int> withdraw(n);
	for (int i = 0; i < n; i++)
		cin >> withdraw[i];

	sort(withdraw.begin(), withdraw.end());

	cout << calcTime(withdraw, n);
}
