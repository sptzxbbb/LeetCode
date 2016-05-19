// soj: 1150. 简单魔板
// Mon Dec 8, 2014--------Shawn Chow
#include "iostream"
#include "list"
#include "algorithm"
using namespace std;

struct board {
  int arr[2][4];
  string p;
};

int n;
bool ans;
list<board> next_path;

bool check(const board& cur, const board& tar) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (cur.arr[i][j] != tar.arr[i][j]) return false;
    }
  }
  return true;
}

void initiate(board& cur) {
  for (int j = 0; j < 4; ++j) {
    cur.arr[0][j] = j + 1;
  }
  for (int i = 0; i < 4; ++i) {
    cur.arr[1][i] = 8 - i;
  }
  cur.p = "";
}

board changeA(board cur) {
  for (int i = 0; i < 4; ++i) {
    swap(cur.arr[0][i], cur.arr[1][i]);
  }
  cur.p += 'A';
  return cur;
}

board changeB(board cur) {
  int n = cur.arr[0][3], m = cur.arr[1][3];
  for (int i = 3; i > 0; --i) {
    cur.arr[0][i] = cur.arr[0][i - 1];
    cur.arr[1][i] = cur.arr[1][i - 1];
  }
  cur.arr[0][0] = n;
  cur.arr[1][0] = m;
  cur.p += 'B';
  return cur;
}

board changeC(board cur) {
  swap(cur.arr[0][1], cur.arr[1][1]);
  swap(cur.arr[0][2], cur.arr[1][1]);
  swap(cur.arr[1][1], cur.arr[1][2]);
  cur.p += 'C';
  return cur;
}

void display(board cur) {
  cout << cur.p.size() << ' ' << cur.p << endl;
}

bool otiose(board cur) {
  char s1 = cur.p[cur.p.size() - 1], s2 = cur.p[cur.p.size() - 2],
    s3 = cur.p[cur.p.size() - 3], s4 = cur.p[cur.p.size() - 4];
  if (s1 == 'A' && s2 == 'A') return true;
  if (s1 == 'B' && s2 == 'B' && s3 == 'B' && s4 == 'B') return true;
  if (s1 == 'C' && s2 == 'C' && s3 == 'C' && s4 == 'C') return true;
  return false;
}

void bfs(board tar) {
  board cur, temp;
  // change A
  while (!next_path.empty() && next_path.front().p.size() <= n) {
    cur = next_path.front();
    if (check(cur, tar)) {
      ans = true;
      display(cur);
      break;
    }

    if (!otiose(cur)) {
      temp = changeA(cur);
      next_path.push_back(temp);
      temp = changeB(cur);
      next_path.push_back(temp);
      temp = changeC(cur);
      next_path.push_back(temp);
    }
    next_path.pop_front();
  }
  if (!ans) cout << "-1" << endl;
}

int main(int argc, char *argv[]) {
  while (cin >> n, n != -1) {
    board tar, cur;
    initiate(cur);
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 4; ++j) {
    	cin >> tar.arr[i][j];
      }
    }
    ans = false;
    next_path.push_back(cur);
    bfs(tar);
    next_path.clear();
  }
  return 0;
}
