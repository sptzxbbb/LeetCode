// soj: 1934. 移动小球
// Thu Dec 18, 2014--------Shawn Chow
#include "iostream"
using namespace std;

struct node {
  node *pre, *next;
  int num;
};

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, m, temp;
    cin >> n >> m;
    node ball[n + 2];
    ball[0].pre = NULL;
    ball[0].next = &ball[1];
    ball[n + 1].pre = &ball[n];
    ball[n + 1].next = NULL;
    for (int i = 1; i <= n; ++i) {
      ball[i].num = i;
      ball[i].pre = &ball[i - 1];
      ball[i].next = &ball[i + 1];
    }

    int dir, x, y;
    for (int i = 0; i < m; ++i) {
      cin >> dir >> x >> y;
      	ball[x].pre->next = ball[x].next;
	ball[x].next->pre = ball[x].pre;
      if (1 == dir) {
	ball[x].next = &ball[y];
	ball[x].pre = ball[y].pre;
	ball[y].pre->next = &ball[x];
	ball[y].pre = &ball[x];
      } else {
	ball[x].pre = &ball[y];
	ball[x].next = ball[y].next;
	ball[y].next->pre = &ball[x];
	ball[y].next = &ball[x];
      }
    }

    node *p = ball[0].next;
    while (p->next) {
      cout << p->num << ' ';
      p = p->next;
    }
    cout << endl;
    
  }
  return 0;
}

