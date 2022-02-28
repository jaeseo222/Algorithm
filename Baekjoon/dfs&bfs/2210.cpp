#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const int SIZE = 1e6;

vector<bool> dfs(vector<vector<int>> arr, vector<bool> visited, int x, int y, int num, int cnt) {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0, -1,1 };

	if (cnt == 5) {
		if (!visited[num]) // 새로운 여섯자리 수가 만들어지면 방문
			visited[num] = true; // 방문체크
		return visited;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
			visited = dfs(arr, visited, nx, ny, num*10 + arr[nx][ny], cnt + 1);
	}
	return visited;
}

int solu(vector<vector<int>> arr) {
	int ans = 0;

	vector<bool> visited(SIZE, false);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			visited = dfs(arr, visited, i, j, arr[i][j], 0);

	for (int i = 0; i < SIZE; i++)
		if (visited[i]) ans++;

	return ans;
}

int main() {
	vector<vector<int>> arr(5, vector<int>(5));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	cout << solu(arr);
}
