#include<iostream>
#include<string>
using namespace std;
int solu(int n) {
	int cnt=0;

	for (int i = 666;; i++) {
		string s = to_string(i);
		if (s.find("666") != s.npos)
			cnt++;
		if (cnt == n)
			return i;
	}
}

int main() {
	int n;
	cin >> n;

	cout << solu(n);
}
