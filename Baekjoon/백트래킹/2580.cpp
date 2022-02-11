#include<iostream>
#include<vector>
using namespace std;

bool row[9][10] = { 0 };
bool col[9][10] = { 0 };
bool area[9][10] = { 0 };
vector<pair<int, int>> blank;

int find_area(int i, int j) {
	return 3 * (i / 3) + (j / 3);
}

bool back(int idx, int size, vector<vector<int>>& ans) {
	if (idx == size)
		return true; //마지막 빈칸까지 채움.

	int x = blank[idx].first; // 빈칸의 위치
	int y = blank[idx].second;
	int a = find_area(x, y); // 빈칸의 area

	for (int i = 1; i <= 9; i++)// 빈칸에 넣을 숫자
		 // 빈칸에 숫자 넣기
		if (!row[x][i] && !col[y][i] && !area[a][i]) {
			row[x][i] = true;
			col[y][i] = true;
			area[a][i] = true;
			ans[x][y] = i;

			// 만약 마지막 빈칸까지 채워졌다면, 여기서 탐색 종료.
			if (back(idx + 1, size, ans)) return true;
			// 막혔다면, 원래대로 돌려놓고 다음 숫자로 넘어감.
			else {
				row[x][i] = false;
				col[y][i] = false;
				area[a][i] = false;
			}
		}
	return false;
}

vector<vector<int>> solution(vector<vector<int>> board) {
	vector<vector<int>> ans(9, vector<int>(9, 0));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int num = board[i][j];
			if (num == 0)
				blank.push_back({ i,j });
			else {
				row[i][num] = true; // i번째 행에 num 이 존재한다.
				col[j][num] = true; // j번째 열에 num 이 존재한다.
				area[find_area(i, j)][num] = true; //i,j 공간에 num 이 존재한다.
				ans[i][j] = num;
			}
		}
	int size = blank.size();
	back(0, size, ans);

	return ans;
}
int main() {
	vector<vector<int>> board(9, vector<int>(9, 0));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	vector<vector<int>> ans = solution(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}
