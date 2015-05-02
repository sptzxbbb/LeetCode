#include "queue"
#include "iostream"
using namespace std;

class mycmp {
public:
  bool operator() (const int& lhs, const int& rhs) const {
    return (lhs > rhs);
  }
};

int main(int argc, char *argv[]) {
  priority_queue<int, vector<int>, mycmp> k;
  k.push(30);
  k.push(100);
  k.push(25);
  k.push(40);
  while (!k.empty()) {
    cout << ' ' << k.top();
    k.pop();
  }
  cout << endl;
  return 0;
}
