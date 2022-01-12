#include<iostream>
#include<vector>
using namespace std;
const int MOD = 100;

typedef long long ll;
vector<int> dp;//1~99원 저장
ll num;//동전개수

void calc() {//각 가격마다 최소 몇 개 필요한지 저장해놓기
	for (int i = 0; i < 100; i++) {
		if (i >= 25) {// 25~99원
			dp[i] = min(dp[i - 25] + 1, dp[i - 10] + 1);
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
		else if (i >= 10)// 10~24 원
			dp[i] = min(dp[i - 10] + 1, dp[i - 1] + 1);
		else// 1~9원
			dp[i] = i;
	}
}

ll modu(ll price, ll ans) {
	while (price) {//못 나눌 떄까지
		int temp = price % MOD;//100으로 나눈 나머지 값의
		ans += dp[temp];//필요한 동전 개수를 더함

		price /= MOD;
	}
	return ans;
}

/*
1,10,25,100,1000,2500,10000,,,,
지불해야 하는 값은 100으로 나눈 나머지
100 이하의 금액인 동전(1,10,25)으로 밖에 못냄

1. 1~99원은 dp에 각각 최소 몇 개 필요한지 저장해놓기
2. 지불금액을 100으로 나누며, 지불금액%100 을 지불하기 위해 필요한 동전 개수 더하기
*/
int main() {
	int t;
	//먼저 1~99원 몇 개 필요한지 계산해놓기
	dp.assign(100, 0);
	calc();

	cin >> t;
	for (int i = 0; i < t; i++) {
		ll price;//초콜릿 가격
		cin >> price;
		num = modu(price, 0);//가격과 처음 동전개수 0개 인자로 넘김

		cout << num << '\n';
	}
}
