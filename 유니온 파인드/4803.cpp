#include<iostream>
#include<vector>
using namespace std;

vector<bool> cycle;//사이클 여부
vector<int> parent;

//find 
int find(int node) {
	if (parent[node] < 0)//루트
		return node;
	return parent[node] = find(parent[node]);
}
//union
void unionInput(int a, int b) {
	int xp = find(a);
	int yp = find(b);

	//cycle주의
	if (xp == yp) {
		cycle[xp] = true;
		return;
	}
	if (cycle[xp] || cycle[yp])//둘 중 하나라도 사이클이 있으면 표시
		cycle[xp] = cycle[yp] = true;

	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
}

//트리 몇 개인지.. cycle여부 벡터랑, 루트뭔지만 알려주는 벡터를 이용해서!
int cntTree(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (parent[i] < 0 && !cycle[i])//루트 정점인데, 사이클도 없을 때
			cnt++;

	return cnt;
}
void printResult(int num, int cnt) {
	cout << "Case " << num;
	if (cnt == 0)
		cout << ": No trees.\n";
	else if (cnt == 1)
		cout << ": There is one tree.\n";
	else
		cout << ": A forest of " << cnt << " trees.\n";
}

int main() {
	int n, m, a, b, t = 0;

	while (true) {
		t++;

		//입력
		cin >> n >> m;
		if (n == 0 && m == 0)//종료
			break;

		parent.assign(n + 1, -1);
		cycle.assign(n + 1, false);

		while (m--) {//무방향 그래프
			cin >> a >> b;
			unionInput(a, b);
		}

		//연산
		int cnt = cntTree(n);

		//출력
		printResult(t, cnt);
	}
}
