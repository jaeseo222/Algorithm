#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 7;
int arr[SIZE];

void solu(int n, int m, int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[idx] = i;
		solu(n, m, idx + 1);
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	solu(n, m, 0);
}
