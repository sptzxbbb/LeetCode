// soj: 1932. Couples
// Thu Dec 18, 2014--------Shawn Chow
#include "iostream"
#include "list"
using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> m;
  while (m--) {
    cin >> n;
    int couple[2 * n + 1], a, b;
    for (int i = 1; i <= n; ++i) {
      cin >> a >> b;
      couple[a] = couple[b] = i;
    }

    list<int> circle;
    for (int i = 1; i <= 2 * n; ++i) {
      circle.push_front(couple[i]);
    }

    list<int>::iterator it1, it2;
    for (int i = 0; i < n; ++i) {
      if (circle.front() == circle.back()) {
	circle.pop_front();
	circle.pop_back();
      } else {
	it1 = circle.begin();
	it2 = it1;
	++it2;
	if (*it1 == *it2) {
	  circle.pop_front();
	  circle.pop_front();
	}
      }
    }

    if (!circle.empty()) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}


// 1 2 3 4 5 6 7 8
