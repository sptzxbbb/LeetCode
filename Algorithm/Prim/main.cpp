#include "iostream"
#include "climits"
#include "algorithm"
using namespace std;
const int MAX = INT_MAX;

int graph[200][200];

int Prim(int n) {
	//  initial, start from node 0
	int dist[n], v = 0;
	bool visited[n];
	for (int i = 0; i < n; ++i) {
		if (graph[v][i] == MAX) {
			dist[i] = MAX;
		} else {
			dist[i] = graph[v][i];
		}

		visited[i] = false;
	}
	visited[v] = true;

	int length = 0;
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
		length += shortest;
		// update sist
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && graph[u][i] != MAX && graph[u][i] < dist[i])
				dist[i] = graph[u][i];
		}
	}
	return length;
}

int main(int argc, char *argv[]) {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				graph[i][j] = MAX;
				if (i == j) graph[i][j] = 0;
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

		int length;
		length = Prim(n);
		cout << length << endl;
	}
	return 0;
}
