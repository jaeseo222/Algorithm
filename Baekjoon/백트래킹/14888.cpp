#include<iostream>
#include<vector>
using namespace std;

const int SIZE = 10e10 + 1;
int maxi = -SIZE;
int mini = SIZE;
int oper[4];//연산자

void solu(int n, vector<int>& arr, int result, int idx) {
	if (idx == n) {
		mini = min(mini, result);
		maxi = max(maxi, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--;
			switch (i) {
			// + - * /
			case 0:	solu(n, arr, result + arr[idx], idx + 1); break;
			case 1: solu(n, arr, result - arr[idx], idx + 1); break;
			case 2: solu(n, arr, result * arr[idx], idx + 1); break;
			case 3: solu(n, arr, result / arr[idx], idx + 1); break;
			}
			oper[i]++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	solu(n, arr, arr[0], 1);
	cout << maxi << '\n' << mini;
}
