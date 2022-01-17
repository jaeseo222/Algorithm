#include<iostream>
#include<vector>
using namespace std;
int solu(int n,int k , vector<int> &coin) {
	int cnt = 0;//필요한 동전 개수
	for (int i = n - 1; i >= 0; i--) {
		if (k == 0)
			break;//원하는 가치 합

		if (coin[i] <= k) {//동전 사용이 가능하면
			cnt += k / coin[i];
			k %= coin[i];
		}
	}
	return cnt;
}

int main() {
	int n, k;

	cin >> n >> k;
	vector<int> coin(n,0);
	
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cout << solu(n,k,coin);
}
