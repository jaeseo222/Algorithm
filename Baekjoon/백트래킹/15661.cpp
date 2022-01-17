#include<iostream>
using namespace std;
const int SIZE = 20;
const int INF = 10e8;

int n;
int answer = INF;
int power[SIZE][SIZE];
bool is_start[SIZE];
int start[SIZE], link[SIZE];//스타트와 링크팀에 속하는 사람

int calcPower(int arr[], int size) {
	int result = 0;

	//모든 Sij의 합
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			result += power[arr[i]][arr[j]]+power[arr[j]][arr[i]];

	return result;
}

void backT(int cnt, int st) {
	if (cnt == n)
		return;//n이면 팀 꾸리기 끝

	if (cnt > 0) {//최소 1명이 팀에 있어야 함
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (!is_start[i])//스타트팀이 아니라면 링크팀으로!
				link[idx++]=i;

		int diff_value = abs(calcPower(link, idx)-calcPower(start, cnt));
		answer = min(answer, diff_value);//최솟값 차이
	}

	for (int i = st; i < n; i++) {
		start[cnt] = i;
		is_start[i] = true;
		backT(cnt+1, i+1);
		//if (i == 0)
		//	return;
		is_start[i] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> power[i][j];//능력치 관계

	backT(0,0);

	cout << answer;
}
