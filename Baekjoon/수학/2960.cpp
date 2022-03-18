#include<iostream>
#include<vector>
using namespace std;

int findNum(int n, int k) {
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (!is_prime[i]) continue;

		for (int j = i; j <= n; j += i) {
			if (!is_prime[j]) continue;
			is_prime[j] = false;
			if (++cnt == k)
				return j;
		}
	}
	return -1;
}

int main(){
	int n, k;
	cin >> n >> k;
	cout << findNum(n, k);
}
