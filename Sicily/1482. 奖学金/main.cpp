// soj: 1482. 奖学金
// Thu Dec 11, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
using namespace std;

struct node {
  int chinese;
  int math;
  int english;
  int id;
};

bool cmp(node a, node b);

int main(int argc, char *argv[]) {
  int n, k = 0;
  while (cin >> n) {
    node stu[n];
    for (int i = 0; i < n; ++i) {
      cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
      stu[i].id = i + 1;
    }
    sort(stu, stu + n, cmp);

    if (k != 0) {
      cout << endl;
    }

    for (int i = 0; i < 5; ++i) {
      cout << stu[i].id << ' ' << stu[i].chinese + stu[i].math + stu[i].english << endl;
    }
    ++k;
  }
  return 0;
}

bool cmp(node a, node b) {
  int p1 = a.chinese + a.math + a.english;
  int p2 = b.chinese + b.math + b.english;
  if (p1 > p2) return true;
  else if (p1 == p2) {
    
    if (a.chinese > b.chinese) return true;
    else if (a.chinese == b.chinese){
      
      if (a.id < b.id) return true;
      else return false;
      
    } else return false;
  } else return false;
}
