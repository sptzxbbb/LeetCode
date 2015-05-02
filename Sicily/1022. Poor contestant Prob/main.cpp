// soj: 1022. Poor contestant Prob
// Thu Dec 25, 2014--------Shawn Chow
#include "algorithm"
#include "cstring"
#include "queue"
#include "cstdio"
using namespace std;

struct stu {
  int solved;
  char name[11];
};

bool cmp(stu a, stu b) {
  if (a.solved > b.solved) return true;
  else return false;
}

class mycmp1 {
public:
  bool operator() (const stu& lhs, const stu& rhs) const {
    return (lhs.solved > rhs.solved);
  }
};

class mycmp2{
public:
  bool operator() (const stu&lhs, const stu& rhs) const {
    return (lhs.solved < rhs.solved);
  }
};
  
int main(int argc, char *argv[]) {
  int n, count = 0;
  scanf("%d", &n);
  while (n--) {
    if (count) printf("\n");
    char command[5];
    priority_queue<stu, vector<stu>, mycmp2> big;
    priority_queue<stu, vector<stu>, mycmp1> small;
    while (scanf("%s", command), strcmp(command, "End") != 0) {
      char name[11];
      int solved;
      if (strcmp(command, "Add") == 0) {
        scanf("%s %d", name, &solved);
        stu temp;
        temp.solved = solved;
        strcpy(temp.name, name);
        if (big.size() == small.size()) {
          if (!small.empty() && temp.solved > big.top().solved
              && temp.solved > small.top().solved) {
            big.push(small.top());
            small.pop();
            small.push(temp);
          } else {
            big.push(temp);
          }
        } else {
          if (big.top().solved > temp.solved) {
            small.push(big.top());
            big.pop();
            big.push(temp);
          } else {
            small.push(temp);
          }
        }
      } else {
        if (big.size() == small.size()) printf("No one!\n");
        else {
          printf("%s\n", big.top().name);
        }
      }
    }

    if (big.size() == small.size()) printf("Happy BG meeting!!\n");
    else {
      printf("%s is so poor.\n", big.top().name);
    }
    count = 1;
  }
  return 0;
}


