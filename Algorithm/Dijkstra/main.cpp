#include "iostream"
#include "climits"
#include "algorithm"
using namespace std;
const int MAX = INT_MAX;

int graph[200][200];

void Dijkstra(int n, int v, int *dist) {
	bool visited[n];
	//  initial
	for (int i = 0; i < n; ++i) {
		if (graph[v][i] == MAX) {
			dist[i] = MAX;
		} else {
			dist[i] = graph[v][i];
		}
		visited[i] = false;
	}
	visited[v] = true;

	for (int i = 0; i < n - 1; ++i) {
		int shortest = MAX;
		int u = v;
		// pick the nearest vertex
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && dist[j] < shortest) {
				shortest = dist[j];
				u = j;
			}
		}
		visited[u] = true;

		// update sist
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && graph[u][i] != MAX)
				dist[i] = min(dist[i], dist[u] + graph[u][i]);
		}
	}
}

int main(int argc, char *argv[]) {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				graph[i][j] = MAX;
			}
		}

		int a, b, x;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> x;
			if (graph[a][b] > x) {
				graph[a][b] = x;
				graph[b][a] = x;
			}
		}

		int s, t;
		cin >> s >> t;
		graph[s][s] = 0;

		int dist[n];
		Dijkstra(n, s, dist);
		if (dist[t] != MAX) cout << dist[t] << endl;
		else cout << -1 << endl;
	}
	return 0;
}
