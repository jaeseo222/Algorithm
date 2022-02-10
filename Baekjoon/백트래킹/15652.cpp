#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 7;
int arr[SIZE];

void solu(int n, int m, int idx, int def) {
	if (def== m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++) {
		arr[def] = i;
		solu(n, m, i, def+1);
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	solu(n, m, 1,0);
}
