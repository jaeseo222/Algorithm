#include<iostream>
using namespace std;
int solu(int n) {
	for (int i = 1; i < n; i++) {
		int temp = i;
		int sum = temp;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) return i;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	cout << solu(n);
}
