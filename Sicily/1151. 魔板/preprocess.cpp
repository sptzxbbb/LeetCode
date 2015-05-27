// soj: 1151. 简单魔板
// Wed Dec 10, 2014--------Shawn Chow
#include "iostream"
#include "list"
#include "algorithm"
#include "cstring"
using namespace std;

struct board {
  char arr[2][4];
  string p;
  int id;
};
bool visit[40321];
int n, factorial[9];
bool ans;
list<board> next_path;

int answer[40321];
string pathway[40321];

bool check(const board& cur, const board& tar);
bool otiose(board cur);
void display(board cur);
void bfs(board tar);
void getFactor();
void initiate(board& cur);
board changeA(board cur);
board changeB(board cur);
board changeC(board cur);
int getid(char arr[][4]);

int main(int argc, char *argv[]) {
  while (cin >> n, n != -1) {
    board tar, cur;
    initiate(cur);
    getFactor();
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 4; ++j) {
    	cin >> tar.arr[i][j];
      }
    }
    tar.id = getid(tar.arr);

    ans = false;
    next_path.push_back(cur);
    bfs(tar);
    next_path.clear();
  }
  return 0;
}



void getFactor() {
  factorial[0] = 1;
  for (int i = 1; i <= 8; ++i) {
    factorial[i] = factorial[i - 1] * i;
  }
}

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
    cur.arr[0][j] = j + 1 + '0';
  }
  for (int i = 0; i < 4; ++i) {
    cur.arr[1][i] = 8 - i + '0';
  }
  cur.p = "";
  cur.id = getid(cur.arr);
  memset(visit, false, sizeof(visit));
}

board changeA(board cur) {
  for (int i = 0; i < 4; ++i) {
    swap(cur.arr[0][i], cur.arr[1][i]);
  }
  cur.p += 'A';
  cur.id = getid(cur.arr);
  return cur;
}

board changeB(board cur) {
  char n = cur.arr[0][3], m = cur.arr[1][3];
  for (int i = 3; i > 0; --i) {
    cur.arr[0][i] = cur.arr[0][i - 1];
    cur.arr[1][i] = cur.arr[1][i - 1];
  }
  cur.arr[0][0] = n;
  cur.arr[1][0] = m;
  cur.p += 'B';
  cur.id = getid(cur.arr);
  return cur;
}

board changeC(board cur) {
  swap(cur.arr[0][1], cur.arr[1][1]);
  swap(cur.arr[0][2], cur.arr[1][1]);
  swap(cur.arr[1][1], cur.arr[1][2]);
  cur.p += 'C';
  cur.id = getid(cur.arr);
  return cur;
}

void display(board cur) {
  if (answer[cur.id] >= 0) cout << answer[cur.id] << ' ' << pathway[cur.di];
  else cout << "-1" << endl;
}

int getid(char arr[][4]) {
  bool used[9];
  memset(used, false, sizeof(used));
  int ans = 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      int less = 0;
      for (int n = 1; n < arr[i][j] - '0'; ++n) {
	if (!used[n]) ++less;
      }
      ans += less * factorial[8 - (i * 4 + j + 1)];
      used[arr[i][j] - '0'] = true;
    }
  }
  return ans;
}

bool otiose(board cur) {
  if (visit[cur.id]) return true;
  else return false;
}

void bfs(board tar) {
  board cur, temp;

  while (!next_path.empty() && next_path.front().p.size() <= n) {
    cur = next_path.front();
    if (check(cur, tar)) {
      ans = true;
      answer[tar.id] = cur.p.size();
      pathway[tar.id] = cur.p;
      break;
    }

    if (!otiose(cur)) {
      temp = changeA(cur);
      next_path.push_back(temp);
      temp = changeB(cur);
      next_path.push_back(temp);
      temp = changeC(cur);
      next_path.push_back(temp);
      visit[getid(cur.arr)] = true;
    }
    next_path.pop_front();
  }
  if (!ans) answer[tar.id] = -1;
}
