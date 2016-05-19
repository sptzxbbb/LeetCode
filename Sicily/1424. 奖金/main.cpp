#include "iostream"
#include "set"
using namespace std;

int n, m, pre, next, sum = 0;
struct node {
  set<int> pre, next;
  int bonus;
};

void cross(int num, node* staff, bool* visit) {
  set<int>::iterator it1 = staff[num].next.begin(), it2 = staff[num].next.end();
  while (it1 != it2) {
    if (staff[*it1].bonus <= staff[num].bonus)
      staff[*it1].bonus = staff[num].bonus + 1;
    staff[*it1].pre.erase(num);
    ++it1;
  }

  visit[num] = true;
  sum += staff[num].bonus;
  staff[num].pre.clear();
  staff[num].next.clear();
}

int main(int argc, char *argv[]) {
  cin >> n >> m;
  node staff[n + 1];
  bool visit[n + 1], ans = true;
  for (int i = 1; i <= n; ++i) {
    staff[i].bonus = 100;
    visit[i] = false;
  }

  for (int i = 0; i < m; ++i) {
    cin >> next >> pre;
    staff[pre].next.insert(next);
    staff[next].pre.insert(pre);
  }
  // visit n node;
  for (int i = 0; i < n; ++i) {
    // search for a node with 0 in-degree;
    for (int j = 1; j <= n; ++j) {
      if (!visit[j] && !staff[j].pre.size()) {
        cross(j, staff, visit);
        break;
      }
    }
  }
  // whether there is a circle
  for (int i = 1; i <= n; ++i) {
    if (!visit[i]) {
      ans = false;
    }
  }

  if (ans) cout << sum << endl;
  else cout << "Poor Xed" << endl;
  return 0;
}


