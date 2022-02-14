#include<iostream>
#include<vector>
using namespace std;

int mini = 1000;
bool team[21];
int score[20][20] = {};
void solu(int n, vector<vector<int>>& arr, int idx, int cnt) {
	vector<int> start;//스타트 팀원
	vector<int> link;// 링크 팀원
	int scoreS = 0;
	int scoreL = 0;

	if (idx == n / 2) {
		//스타트, 링크 팀원 나누기
		for (int i = 0; i < n; i++)
			if (team[i])
				start.push_back(i);
			else
				link.push_back(i);

		for(int i=0;i<n/2;i++)
			for (int j = 0; j < n / 2; j++) {
				scoreS += score[start[i]][start[j]];
				scoreL += score[link[i]][link[j]];
			}

		mini = min(mini, result);
		return;
	}

	for (int i = idx; i <= n; i++)
		if (!team[i]) {
			team[i] = true;
			solu(n, arr, i, cnt+1);
			team[i] = false;
		}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	solu(n, arr, 0, 0);
	cout << mini;
}
