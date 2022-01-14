#include<iostream>
using namespace std;
const int SIZE = 15;
int n;
int ans;
bool check_col[SIZE + 1];//행
bool check_left[SIZE * 2];//좌하향
bool check_right[SIZE * 2];//우하향
void backT(int cnt) {
	if (cnt == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++)
		if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) {
			check_col[i] = true;
			check_left[cnt + i] = true;
			check_right[cnt - i + n] = true;
			backT(cnt + 1);
			check_col[i] = false;
			check_left[cnt + i] = false;
			check_right[cnt - i + n] = false;
		}
}
int main() {
	ans = 0;
	cin >> n;
	backT(0);
	cout << ans;
}
