#include<iostream>
#include<vector>

using namespace std;
int solu(int r, int c, vector<vector<char>>& arr) {
	// 처음이 B로 시작할 경우로 생각
	int ans = 0;
	for (int i = r; i < r + 8; i++) {
		for (int j = c; j < c + 8; j++)
			if (((i + j) % 2 == 0 && arr[i][j] != 'B') || ((i + j) % 2 && arr[i][j] != 'W'))
				ans++;
	}
	//B, W 중 뭘로 시작해야 덜 수정할 지
	return min(ans, 64 - ans);
}
int main() {
	int n, m;
	cin >> n >> m;
	int ans = n * m;
	vector<vector<char>> arr(n, vector<char>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i <= n - 8; i++)
		for (int j = 0; j <= m - 8; j++) {
			ans = min(ans, solu(i, j, arr));
		}
	cout << ans;
}
