// soj: 1024. Magic Island
// Mon Dec 29, 2014--------Shawn Chow
#include "iostream"
#include "vector"
#include "cstring"
#include "cstdio"
using namespace std;

struct node {
  vector< pair<int, int> > next;
};
int Max;
bool visit[10001];

void DFS(node* city, int cur, int cur_path) {
  if (cur_path > Max) Max = cur_path;
  visit[cur] = true;
  for (int i = 0; i < city[cur].next.size(); ++i) {
    if (!visit[city[cur].next[i].first])
      DFS(city, city[cur].next[i].first, cur_path + city[cur].next[i].second);
 }
  visit[cur] = false;
}

int main(int argc, char *argv[]) {
  int N, K;
  while (scanf("%d %d", &N, &K) != EOF) {
    Max = 0;
    node city[N + 1];
    memset(visit, false, sizeof(visit));
    int x, y, d;
    for (int i = 0; i < N - 1; ++i) {
      scanf("%d %d %d", &x, &y, &d);
      pair<int, int> temp(y, d), temp2(x, d);
      city[x].next.push_back(temp);
      city[y].next.push_back(temp2);
    }
    DFS(city, K, 0);
    printf("%d\n", Max);
  }
  return 0;
}
