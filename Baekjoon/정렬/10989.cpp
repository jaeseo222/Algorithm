#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a;
	cin >> n;
	int arr[10001] = {0};

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}

	for (int i = 0; i < 10001; i++)
		while (arr[i]--)
			cout << i << '\n';

}
