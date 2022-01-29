#include<iostream>
#include<vector>
using namespace std;
void fibo(int n) {
	// 0과 1의 count점화식 dp
	vector<int> zeroNum(n + 2, 0);
	vector<int> oneNum(n + 2, 0); // 범위제어를 위해 +2

	//초기화
	zeroNum[0] = 1;
	oneNum[1] = 1;
	for (int i = 2; i <= n; i++) {
		zeroNum[i] = zeroNum[i - 1] + zeroNum[i - 2];
		oneNum[i] = oneNum[i - 1] + oneNum[i - 2];
	}
	cout << zeroNum[n] << " "<<oneNum[n] << '\n';
}

int main() {
	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		fibo(n);
	}
}
