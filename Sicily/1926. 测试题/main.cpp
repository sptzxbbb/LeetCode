// soj: 1926. 测试题
// Fri Dec 12, 2014--------Shawn Chow

class NumCal {
public:
  int sum();
  NumCal();
  NumCal(int* new_p, int new_size);
private:
  int *p;
  int size;
};

NumCal::NumCal() {
  size = 0;
  p = 0;
}

NumCal::NumCal(int *new_p, int new_size) {
  p = new int[new_size];
  size = new_size;
  for (int i = 0; i < new_size; ++i) {
    *(p + i) = *(new_p + i);
  }
}

int NumCal::sum() {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += *(p + i);
  }
  return sum;
}
