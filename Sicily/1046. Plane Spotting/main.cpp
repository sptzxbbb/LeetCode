// soj: 1046. Plane Spotting
// Thu Dec 25, 2014--------Shawn Chow
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

struct period {
  double average;
  int length;
  int start, end;
};

bool cmp(period a, period b) {
  if (a.average != b.average) return a.average > b.average;
  else {
    if (a.length != b.length) return a.length > b.length;
    else {
      return a.end < b.end;
    }
  }
}

int main(int argc, char *argv[]) {
  int n, count = 1;
  cin >> n;
  while (n--) {
    int quarter, num, length;
    cin >> quarter >> num >> length;
    int arr[quarter + 1];
    for (int i = 1; i <= quarter; ++i) {
      cin >> arr[i];
    }

    vector<period> k;
    int l = length, pos = 1;
    while (l <= quarter) {
      if (pos + l - 1 <= quarter) {
        period temp;
        temp.average = 0;
        for (int i = pos; i <= pos + l - 1; ++i) {
          temp.average += arr[i];
        }
        temp.start = pos;
        temp.average /= l;
        temp.end = pos + l - 1;
        temp.length = l;
        k.push_back(temp);
        ++pos;
      } else {
        pos = 1;
        ++l;
      }
    }
    int size = k.size();
    sort(k.begin(), k.end(), cmp);
    cout << "Result for run " << count << ':' << endl;
    size= min(size, num);
    for (int i = 0; i < size; ++i) {
      cout << k[i].start << '-' << k[i].end << endl;
    }
    ++count;
  }
  return 0;
}

