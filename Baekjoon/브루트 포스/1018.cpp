#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 64;

int solu(vector<vector<char>> &b, int row, int col) {
	int b_cnt=0;//맨 처음 B 기준으로, 수정해야 되는 개수

	for(int i=0;i<8;i++)
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && b[row + i][col + j] != 'B')
				b_cnt++;
			else if ((i + j) % 2 && b[row + i][col + j] != 'W')
				b_cnt++;
		}

	//B, W 중 뭘로 시작해야 덜 수정할 지
	if (b_cnt > SIZE / 2)
		return SIZE - b_cnt;
	return b_cnt;
}

int main() {
	int n, m, ans=SIZE+1;
	cin >> n >> m;

	vector<vector<char>> board(n,vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	//범위 주의
	for (int i = 0; i <= n-8; i++)
		for (int j = 0; j <= m-8; j++) {
			int cnt = solu(board, i, j);
			if (ans > cnt) ans = cnt;
		}

	cout << ans;
}
