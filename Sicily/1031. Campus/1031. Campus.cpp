#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <queue>
using namespace std;

const int MAXN = 200;

struct edge {
    int to;
    int weight;
    edge(int t, int w) : to(t), weight(w) {}
};

int dijkstra(int source, int dest, vector<edge> g[], int n) {
    priority_queue<pair<int, int> > q;
    int dis[n];
    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }
    dis[source] = 0;
    q.push(make_pair(dis[source], source));
    while (!q.empty()) {
        pair<int, int> e = q.top();
        q.pop();
        int cur = e.second;
        if (e.first != dis[cur]) {
            continue;
        }
        for (int i = 0; i < (int)g[cur].size(); i++) {
            int to = g[cur][i].to;
            int weight = g[cur][i].weight;
            if (dis[to] > dis[cur] + weight) {
                dis[to] = dis[cur] + weight;
                q.push(make_pair(dis[to], to));
            }
        }
    }
    if (dis[dest] == INT_MAX) {
        return -1;
    } else {
        return dis[dest];
    }
}

int main(int argc, char *argv[]) {
    int C, N;
    cin >> C;
    while (C--) {
        // number of edge
        cin >> N;
        string a, b;
        int weight, n = 0;
        map<string, int> m;
        vector<edge> graph[MAXN];
        for (int i = 0; i < N; i++) {
            cin >> a >> b >> weight;
            if (!m.count(a)) {
                //m[a] = n++;
                m.insert(make_pair(a, n++));
            }
            if (!m.count(b)) {
                //m[b] = n++;
                m.insert(make_pair(b, n++));
            }
            edge e1(m[b], weight);
            edge e2(m[a], weight);
            graph[m[a]].push_back(e1);
            graph[m[b]].push_back(e2);
        }
        string source, dest;
        cin >> source >> dest;
        if (source == dest) {
            cout << 0 << endl;
        } else if (!m.count(source) || !m.count(dest)) {
            cout << -1 << endl;
        } else {
            cout << dijkstra(m[source], m[dest], graph, n) << endl;
        }
    }
    return 0;
}
