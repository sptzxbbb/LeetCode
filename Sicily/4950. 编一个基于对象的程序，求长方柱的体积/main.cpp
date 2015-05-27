// soj: 4950. 编一个基于对象的程序，求长方柱的体积
// Fri Dec 12, 2014--------Shawn Chow
#include "iostream"
using namespace std;

class cuboid {
public:
  
  cuboid(int a, int b, int c) {
    length = a;
    width = b;
    height = c;
  }
  
  ~cuboid() {}

  int volume() {
    return length * width * height;
  }
  
private:
  
  int length, width, height;
};


int main(int argc, char *argv[]) {
  int l, w, h;
  cin >> l >> w >> h;
  cuboid a(l, w, h);
  cin >> l >> w >> h;
  cuboid b(l, w, h);
  cin >> l >> w >> h;
  cuboid c(l, w, h);

  cout << a.volume() << endl;
  cout << b.volume() << endl;
  cout << c.volume() << endl;
  return 0;
}

