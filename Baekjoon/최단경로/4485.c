#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100000

const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨
const int SIZE = 126;

typedef struct node {
	int r, c;
	int cost;
}Node;

Node heap[MAX_HEAP];
int heapCount = 0;

void swap(Node* a, Node* b) {
	Node tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int cost, int r, int c) {
	Node temp;
	temp.r = r;
	temp.c = c;
	temp.cost = cost;

	heap[++heapCount] = temp;

	int child = heapCount;
	int parent = child / 2;

	while (child > 1 && heap[child].cost < heap[parent].cost) {
		swap(&heap[child], &heap[parent]);
		child = parent;
		parent /= 2;
	}
}

Node pop() {
	Node removed = heap[1];
	swap(&heap[1], &heap[heapCount]);

	heapCount--;

	int parent = 1;
	int child = 2;

	while (child <= heapCount) {
		if (child + 1 <= heapCount && heap[child + 1].cost < heap[child].cost)
			child = child + 1;

		if (heap[parent].cost <= heap[child].cost)
			break;

		swap(&heap[parent], &heap[child]);

		parent = child;
		child *= 2;
	}
	return removed;
}

int dijkstra(int n, int board[][SIZE]) {
	// 상 하 좌 우
	int dr[4] = { -1, 1, 0, 0 }; // row
	int dc[4] = { 0, 0, -1, 1 }; // col

	int dist[SIZE][SIZE] = { INF, }; // 최소 금액 저장
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			dist[i][j] = INF;
	//Node heap[MAX_HEAP]; 

	// 시작 위치 초기화
	dist[0][0] = board[0][0]; // (0, 0)부터 시작
	push(dist[0][0], 0, 0);
	
	//BFS
	int num = 1;
	while (heapCount != 0) {
		Node node = pop();

		int weight = node.cost;
		int row = node.r;
		int col = node.c;

		if (row == n - 1 && col == n - 1) // 제일 오른쪽 아래 칸 (n-1, n-1) 도착 시, 최소 금액 리턴 및 종료
			return weight;

		if (weight > dist[row][col]) // 이미 확인했던 좌표(dist에 이미 최소 금액이 저장돼 있음)
			continue;

		for (int i = 0; i < 4; i++) {
			int nr = row + dr[i]; // 연결된 좌표 next row
			int nc = col + dc[i]; // 연결된 좌표 next col
			if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) // 범위를 벗어날 시, 제어
				continue;

			int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
			if (dist[nr][nc] > next_weight) { // 더 적게 잃을 수 있다면
				dist[nr][nc] = next_weight;
				push(next_weight, nr, nc);
			}
		}
	}
}

int main() {
	int n, num = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;

		int board[SIZE][SIZE] = { 0, }; // 인접리스트
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &board[i][j]);

		printf("Problem %d: %d\n", num++, dijkstra(n, board));
	}
}
