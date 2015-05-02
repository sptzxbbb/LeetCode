// soj: 1509. Rails
// Mon Dec 15, 2014--------Shawn Chow
#include "iostream"
#include "stack"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n, n) {
    while (1) {
      int next;
      stack<int> station, A;
      bool end = false;

      for (int i = n; i >= 1; --i) {
	A.push(i);
      }
      
      for (int i = 0; i < n; ++i) {
	cin >> next;
	if (!next) { // 0 ends
	  end = true;
	  break;
	} else {
	  while ((station.empty() || station.top() < next) && !A.empty()) {
	    if (!A.empty()) {
	      station.push(A.top());
	      A.pop();
	    }
	  }
	  if (!station.empty() && station.top() == next) station.pop();
	  // else if (!station.empty() && station.top() > next) break;
	}
      }
      if (end) break;
      if (station.empty() && A.empty()) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    cout << endl;
  }
  return 0;
}


// 5 1 2 3 4
