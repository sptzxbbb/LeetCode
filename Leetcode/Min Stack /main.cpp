#include <iostream>
#include <stack>
using namespace std;
const int Max = 999999;

class MinStack1 {
public:
  MinStack1() {
    roof = -1;
    roof2 = -1;
  }

  void push(int x) {
    if (roof == Max - 1) return;
    stack[++roof] = x; 
    if (-1 == roof2 || stack2[roof2] >= x) {
      stack2[++roof2] = x;
    }
  }

  void pop() {
    if (roof2 >= 0 && roof >= 0 && stack2[roof2] == stack[roof]) {
      --roof2;
      --roof;
    } else if (roof >= 0) {
      --roof;
    }
  }

  int top() {
    if (roof >= 0) return stack[roof];
  }

  int getMin() {
    if (roof2 >= 0) return stack2[roof2];
  }
private:
  int stack[Max], roof;
  int stack2[Max], roof2;
};

class MinStack {
public:
  void push(int x) {
    stk.push(x);
    if (min.empty() || x <= min.top()) min.push(x);
   }

  void pop() {
    if (!min.empty() && !stk.empty() && stk.top() == min.top()) {
      stk.pop();
      min.pop();
    } else if (!stk.empty()) {
      stk.pop();
    }
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return min.top();
  }
private:
  stack<int> stk;
  stack<int> min;
};

int main(int argc, char *argv[]) {
  MinStack a;
  a.push(-3);
  cout << a.getMin() << endl;
  return 0;
}
