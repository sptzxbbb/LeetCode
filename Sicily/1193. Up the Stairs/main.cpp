//  1193.Up the Stairs--------Shawn Chow
//  Thu Nov 27, 2014
#include "iostream"
#include "algorithm"

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int N, F, B;
    cin >> N >> F >> B;

    int round = B / N, porter = B % N, flag;
    int distance[N + 1];

    for (int i = 0; i < N; ++i) {
      cin >> distance[i] >> flag;
      if (flag == 1) distance[i] = 2 * F - distance[i];
    }
    
    sort(distance, distance + N);

    if (porter != 0) {
      porter--;
      round++;
    } else {
      porter = N - 1;
    }

    cout << distance[porter] + (2 * round - 1) * F << endl;
    
  }

  return 0;
}                                 
