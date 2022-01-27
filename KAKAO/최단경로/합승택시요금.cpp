#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7 * 2; //최대 n-1개의 간선을 지나게 됨

//간선을 인접 행렬 그래프에 삽입
vector<vector<int>> fillGraph(int n, vector<vector<int>> &fares) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0;

    for (int i = 0; i < fares.size(); i++) { //양방향 그래프
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    return graph;
}

void floydWarshall(vector<vector<int>> &graph, int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                graph[i][j] = min(graph[i][j], dist); //i->j와 i->k->j 중 더 짧은 경로
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> graph = fillGraph(n, fares);
    floydWarshall(graph, n);

    for (int i = 1; i <= n; i++) { //i번째 지점까지 합승
        //지금까지의 최단거리와 합승한 최단거리 비교
        //이동 불가능한 경우(INF)은 min 조건에 의해 자동으로 고려되지 않음
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    return answer;
}

int main() {
    vector<vector<int>> fares = {{4, 1, 10},
                                 {3, 5, 24},
                                 {5, 6, 2},
                                 {3, 1, 41},
                                 {5, 1, 24},
                                 {4, 6, 50},
                                 {2, 4, 66},
                                 {2, 3, 22},
                                 {1, 6, 25}};
    int ans = solution(6, 4, 6, 2, fares);
    cout << ans;
}
