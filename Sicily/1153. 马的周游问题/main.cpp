// Problem#: 11880
// Submission#: 3135577
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

typedef struct position {
  int x;
  int y;
  int branch;
  position(int a = 0, int b = 0) : x(a), y(b) {};
} pos;

pos dev[8] = {
  {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
  {1, 2}, {2, 1}, {2, -1}, {1, -2}
};

void initialize();
bool check(int x, int y);
bool special_judge(pos cur, int NumOfStep);
bool cmp(pos a, pos b);
int cal(pos a);

const int scale = 8;
int chess[scale][scale];
int path[64];

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n && n != -1) {
    initialize();
    pos cur;
    cur.x = (n - 1) / scale;
    cur.y = n - (cur.x * scale) - 1;
    path[0] = n;
    chess[cur.x][cur.y] = 1;
    special_judge(cur, 1);
  }

}

void initialize() {
  for (int i = 0; i < scale; ++i) {
    for (int j = 0; j < scale; ++j) {
      chess[i][j] = 0;
    }
  }
}


bool special_judge(pos cur, int NumOfStep) {
  if (NumOfStep == scale * scale) {
    for (int i = 0; i < scale * scale - 1; ++i) {
      cout << path[i] << ' ';
    }
    cout << path[scale * scale - 1] << endl;
    return true;
  } else {

    
    // search for next movement
    pos next;
    vector<pos> choice;
    for (int i = 0; i < 8; ++i) {
      next.x = cur.x + dev[i].x;
      next.y = cur.y + dev[i].y;
     
      if (check(next.x, next.y)) {
        next.branch = cal(next);
        choice.push_back(next);
      }
    }

    // sort to find the best choice
    sort(choice.begin(), choice.end(), cmp);
    
    // move to next optimized position
    for (int i = 0; i < choice.size(); ++i) {
      chess[choice[i].x][choice[i].y] = 1;
      path[NumOfStep] = choice[i].x * 8 + (choice[i].y + 1);
      if (special_judge(choice[i], NumOfStep + 1)) {
        return true;
      }
      chess[choice[i].x][choice[i].y] = 0;
    }
  }
  return false;
}

bool cmp(pos a, pos b) {
  return (a.branch < b.branch);
}

int cal(pos cur) {
  int sum = 0;
  pos next;
  for (int i = 0; i < 8; ++i) {
    next.x = cur.x + dev[i].x;
    next.y = cur.y + dev[i].y;
    if (check(next.x, next.y)) {
      sum++;
    }
  }
  return sum;
}

bool check(int x, int y) {
  if (x > (scale - 1) || x < 0 || y > (scale - 1) || y < 0 || chess[x][y] > 0) {
    return false;
  } else {
    return true;
  }
}                                 
