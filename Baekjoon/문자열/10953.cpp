#include<iostream>
#include<vector>
using namespace std;

int sum(string str) {
	int ans = 0;
	ans += (str[0] - '0') + (str[2] - '0');
	return ans;
}

int main() {
	int n;
	string str;
	cin >> n;

	while (n--) {
		cin >> str;
		cout << sum(str) << '\n';
	}
}
