#include<iostream>
using namespace std;
const int SIZE = 8;

//백트래킹 전역변수 주의
int n, m;
int num[SIZE];
bool check[SIZE + 1];//사용했는지 여부
void backT(int cnt) {
	if (cnt == m) {//기저 조건
		for (int i = 0; i < cnt; i++)
			cout<<num[i]<<' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
		if (!check[i]) {
			num[cnt] = i;
			check[i] = true;
			backT(cnt + 1);//다음 인덱스로 호출
			check[i] = false;//갔다 왔으면 풀어주기
		}
}

int main() {
	cin >> n >> m;
	backT(0);
}
