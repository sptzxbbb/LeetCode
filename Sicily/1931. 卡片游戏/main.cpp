// soj: 1931. 卡片游戏
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "list"
using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    list<int> deck;
    for (int i = 1; i <= n; ++i) {
      deck.push_back(i);
    }

    while (deck.size() != 1) {
      cout << deck.front() << ' ';
      deck.pop_front();
      deck.push_back(deck.front());
      deck.pop_front();
    }
    cout << deck.front() << ' ' << endl;
  }
  return 0;
}

