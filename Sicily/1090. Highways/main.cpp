// soj: 1090. Highways
// Sat Dec 27, 2014--------Shawn Chow
#include "iostream"
#include "cstring"
using namespace std;

const int MAX = 99999;
const int VNUM = 500;
int edge[VNUM][VNUM], lowcost[VNUM], closeset[VNUM];
bool used[VNUM];
// lowcost : the minimum edge from U to V - U
// closeset : the vertex to which the edge is attached


void prim(int vertex) {
  int next, min, max = -1;
  
  // initialize;
  for (int i = 0; i < vertex; ++i) {
    lowcost[i] = edge[0][i];
    closeset[i] = 0;
    used[i] = 0;
  }

  used[0] = true; // begin with node 0;
  for (int i = 1; i < vertex; ++i) {
    next = 0;
    min = MAX;
    // search for the shortest edge
    for (int k = 1; k < vertex; ++k) {
      if (!used[k] && lowcost[k] < min) {
        min = lowcost[k];
        next = k;
      }
    }
    
    // cout << next + 1 << ' ' << closeset[next] + 1 << endl;
    used[next] = true;
    if (max < min) max = min;
    for (int k = 1; k < vertex; ++k) {
      if (!used[k] && edge[next][k] < lowcost[k]) {
        lowcost[k] = edge[next][k];
        closeset[k] = next;
      }
    }
  }
  cout << max << endl;
}

int main(int argc, char *argv[]) {
  int t, count = 0;
  cin >> t;
  while (t--) {
    if (count) cout << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> edge[i][j];
      }
    }
    prim(n);
    count = 1;
  }
  return 0;
}


