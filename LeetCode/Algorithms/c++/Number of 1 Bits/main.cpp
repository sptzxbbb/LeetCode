#include "iostream"
#include "stdint.h"

using namespace std;

class solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    uint32_t quotient = n, reminder;
    while (quotient) {
      reminder = quotient % 2;
      quotient >>= 1;
      count += reminder;
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
solution a;
cout << a.hammingWeight(11) << endl;
return 0;
}
