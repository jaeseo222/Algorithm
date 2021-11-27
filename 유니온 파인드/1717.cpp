#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;//부모

//find
int findParent(int node) {
	if (parent[node] <0)//값이 음수면 루트 정점
		return node;

	return parent[node] = findParent(parent[node]);//완전 최종 루트로 갱신
}
//union
void unionInput(int x, int y) {
	int xp = findParent(x);//x의 부모
	int yp = findParent(y);

	if (xp == yp)//사이클
		return;
	if (parent[xp] < parent[yp]) {//xp노드가 음수일경우, 루트
		parent[xp] += parent[yp];//항상 음수가 더해질 것임., -1-3-2..
		parent[yp] = xp;//sub의 루트를 xp로 갱신
	}
	else {//yp노드가 루트
		parent[yp] += parent[xp];//항상 음수가 더해질 것임., -1-3-2..
		parent[xp] = yp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cmd, a, b;

	//입력
	cin >> n >> m;
	parent.assign(n + 1, -1);//-1로 초기화

	while (m--) {
		cin >> cmd >> a >> b;

		//union
		if (cmd == 0)
			unionInput(a, b);

		//find
		if (cmd == 1) {
			if (findParent(a) == findParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
