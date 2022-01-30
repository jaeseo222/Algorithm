#include <stdio.h>
#include <stdlib.h>
const int INF = 1e7 * 2; // 최대 n-1개의 간선을 지나게 됨

int min(int a, int b) {
	return a < b ? a : b;
}

int** fillGraph(int n, int** fares) {
	int** graph = (int**)malloc(sizeof(int*) * (n + 1));

	for (int i = 1; i <= n; i++) {
		graph[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (int j = 1; j <= n; j++)
			graph[i][j] = INF;
		graph[i][i] = 0;// 자기 자신과의 비용은 0
	}

	// 동적할당된 fares의 원소 개수 구하기 : _msize(fares) / sizeof(int*)
	for (int i = 0; i < _msize(fares) / sizeof(int*); i++) { // a->b 와 b->a 의 비용이 같은 양방향 그래프
		graph[fares[i][0]][fares[i][1]] = fares[i][2];
		graph[fares[i][1]][fares[i][0]] = fares[i][2];
	}
	return graph;
}

void floydWarshall(int** graph, int n) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				// i->j와 i->k->j 중 더 적은 비용으로 갱신
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}
int solution(int n, int s, int a, int b, int** fares) {
	int answer = INF;
	int** graph = fillGraph(n, fares); // 초기화

	floydWarshall(graph, n); // 플로이드-워셜 적용
	for (int i = 1; i <= n; i++) {
		// s에서 출발해서 i까지 합승 후, 따로 따로 i부터 a까지, i부터 b까지 가는 최소 택시비용
		// 최소비용(s->i) + 최소비용(i->a) + 최소비용(i->b) 이 최소값일 때 최소 비용이 됨
		// 이어진 경로가 없는 경우(INF)는 min 조건에 의해 자동으로 고려되지 않음
		answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
	}
	return answer;
}
int main() {
	// 예시
	/*
	동적할당을 위해 직접 입력

	4 1 10
	3 5 24
	5 6 2
	3 1 41
	5 1 24
	4 6 50
	2 4 66
	2 3 22
	1 6 25
	*/
	int** fares = (int**)malloc(sizeof(int*) * 9);
	for (int i = 0; i < 9; i++) {
		fares[i] = (int*)malloc(sizeof(int) * 3);
		for (int j = 0; j < 3; j++)
			scanf("%d", &fares[i][j]);
	}
	int ans = solution(6, 4, 6, 2, fares);
	printf("%d", ans);
}
