#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE = 7;

int n, m, leng;
int num[SIZE],ans[SIZE];

void backT(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << ans[i]<<' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < leng; i++){
		ans[cnt] = num[i];
		backT(cnt+1);
	}
}

int main() {
	cin >> n >> m;

	vector<bool> check(10000, false);
	//애초에 중복인 수를 제거해가며 저장
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (!check[a])
			num[leng++] = a;
		check[a] = true;
	}

	sort(num, num + leng);//정렬

	backT(0);
}
