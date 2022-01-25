#include<stdio.h>
#define MAX_HEAP 100000

const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨
const int SIZE = 126;

typedef struct { // heap 노드
	int r, c; // 현재 위치 좌표
	int cost; // 현재 누적 금액
}element;

typedef struct { // heap 자료구조
	element heap[MAX_HEAP];
	int size;
}Heap;

element make_node(int cost, int r, int c) { // 새로운 node를 생성
	element item;
	item.cost = cost;
	item.r = r;
	item.c = c;
	return item;
}

void push(Heap* h, element item) {
	int i = ++(h->size); // 우선, 새로운 노드를 heap의 마지막에 위치

	// 루트노드가 아니며, 새로운 노드 값이 적절한 위치를 찾을 때까지 반복
	// i : 자식 , i/2 : 부모
	while (i != 1 && item.cost < h->heap[i/2].cost) {
		h->heap[i] = h->heap[i / 2]; // 자식 노드와 부모노드 교환 
		i /= 2; // 위로 이동
	}
	h->heap[i] = item; // 새로운 노드 삽입
}

element pop(Heap* h) {
	element removed, temp;
	removed = h->heap[1]; // 반환할 노드 저장
	temp = h->heap[(h->size)--]; // 마지막 노드

	int parent = 1, child = 2;

	while (child <= h->size) {
		// 왼쪽 자식, 오른쪽 자식 노드 중 더 작은 노드
		if (child < h->size && h->heap[child + 1].cost < h->heap[child].cost)
			child++;

		// 마지막 노드가 자식 노드보다 작으면 종료
		if (temp.cost <= h->heap[child].cost)
			break;

		// 부모노드와 자식노드 교환
		h->heap[parent] = h->heap[child];

		// 아래로 이동
		parent = child;
		child *= 2;
	}

	// 마지막 노드를 적절한 위치에 삽입
	h->heap[parent] = temp;

	return removed;// 노드 반환
}

int dijkstra(int n, int board[][SIZE]) {
	// 상 하 좌 우
	int dr[4] = { -1, 1, 0, 0 }; // row
	int dc[4] = { 0, 0, -1, 1 }; // col

	int dist[SIZE][SIZE];// 최소 금액 저장
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = INF;

	Heap pq; // 우선순위 큐(최소힙)
	pq.size = 0; // 우선순위 큐 초기화

	// 시작 위치 초기화
	dist[0][0] = board[0][0]; // (0, 0)부터 시작
	push(&pq, make_node(dist[0][0], 0, 0));

	//BFS
	while (pq.size != 0) {
		// 현재 잃은 금액과 위치
		element node = pop(&pq);
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
				push(&pq, make_node(next_weight, nr, nc));
			}
		}
	}
}

int main() {
	int n, num = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;

		int board[SIZE][SIZE]; // 인접리스트
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &board[i][j]);

		printf("Problem %d: %d\n", num++, dijkstra(n, board));
	}
}
