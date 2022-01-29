#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;

	// 미리 만들어 놓기
	int fiboArr[41] = {0,1};
	for (int i = 2; i <41; i++)
		fiboArr[i] = fiboArr[i - 1] + fiboArr[i - 2];

	while(t--){
		cin >> n;
		if (n == 0)
			cout << "1 0";
		else
			cout << fiboArr[n - 1] << ' ' << fiboArr[n];
		cout << '\n';
	}
}
