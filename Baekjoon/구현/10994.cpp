#include<iostream>
#include<vector>
using namespace std;

void fillStar(vector<vector<char>> &star,int w,  int row, int col) {
	if (w == 1){ // 종료 조건
		star[row][col] = '*';
		return;
	}

	fillStar(star, w-4 , row+2, col+2);

	for (int i = row; i < row + w; i++)
		star[i][col] = star[row][i] = star[i][col + w - 1] = star[row + w - 1][i] = '*';
}

int main() {
	int n, w;
	cin >> n;
	w = 4 * n - 3;

	vector<vector<char>> star(w, vector<char>(w,' '));

	fillStar(star,w, 0,0);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++)
			cout << star[i][j];
		cout << '\n';
	}
}
