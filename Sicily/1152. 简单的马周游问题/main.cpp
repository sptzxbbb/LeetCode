// soj: 1152. 简单的马周游问题
// Thu Dec 4, 2014--------Shawn Chow
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


int chess[5][6];
int path[30];

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n && n != -1) {
    initialize();
    pos cur;
    cur.x = (n - 1) / 6;  // n = 22, cur.x = 3
    cur.y = n - (cur.x * 6) - 1; // cur.y = 22 - 3 * 6 - 1 = 3 
    path[0] = n;
    chess[cur.x][cur.y] = 1;
    special_judge(cur, 1);
  }

}

void initialize() {
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      chess[i][j] = 0;
    }
  }
}


bool special_judge(pos cur, int NumOfStep) {
  if (NumOfStep == 30) {
    for (int i = 0; i < 30 - 1; ++i) {
      cout << path[i] << ' ';
    }
    cout << path[30 - 1] << endl;
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
      path[NumOfStep] = choice[i].x * 6 + (choice[i].y + 1);
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
  if (x > (5 - 1) || x < 0 || y > (6 - 1) || y < 0 || chess[x][y] > 0) {
    return false;
  } else {
    return true;
  }
}                                 
