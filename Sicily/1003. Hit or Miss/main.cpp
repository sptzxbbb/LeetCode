// soj: 1003. Hit or Miss
// Sun Dec 28, 2014--------Shawn Chow
#include "iostream"
#include "queue"
using namespace std;

struct player {
  queue<int> deck;
  int call;
  int last;
};

int main(int argc, char *argv[]) {
  int t, count = 0;
  cin >> t;
  while (t--) {
    int num, card;
    cin >> num;
    player p[num];
    // initialization
    for (int i = 0; i < num; ++i) {
      p[i].call = 0;
    }
    for (int i = 0; i < 52; ++i) {
      cin >> card;
      p[0].deck.push(card);
    }
    ++count;

    bool empty = true;
    int discard = 0, time = 0;
    while (time < 10000) {
      // start the call
      for (int i = 0; i < num; ++i) {
        // the player with cards call;
        if (!p[i].deck.empty()) ++p[i].call;
        else continue;
        // when reaching 13, start over at 1
        if (14 == p[i].call) p[i].call = 1;

        // the top card;
        card = p[i].deck.front();
        p[i].deck.pop();
          
        // if the call match the top card;
        if (p[i].call == card) {
          // the card to be passed or discarded;
          if (i != num - 1) {
            p[i + 1].deck.push(card);
          } else { // the last one
            ++discard;
          }
          // empty his hand
          if (p[i].deck.empty()) p[i].last = card;
        } else {
          p[i].deck.push(card);
        }
    
        // check if the game is over

        if (52 == discard) {
          cout << "Case " << count << ": ";
          for (int i = 0; i < num - 1; ++i) {
            cout << p[i].last << ' ';
          }
          cout << p[num - 1].last << endl;
          break;
        }
      }
      ++time;
    }
    if (discard != 52) cout << "Case " << count << ": unwinnable" << endl;
  }
  return 0;
}
