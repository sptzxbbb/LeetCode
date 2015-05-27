//  1198. Substring--------Shawn Chow
//  Thu Nov 27, 2014

#include "iostream"
#include "string"
using namespace std;

bool cmp(string a, string b);

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    string substring[m];
    for (int i = 0; i < m; ++i) {
      cin >> substring[i];   
    }

    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        if (!cmp(substring[i], substring[j])) {
          string temp;
          temp = substring[i];
          substring[i] = substring[j];
          substring[j] = temp;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      cout << substring[i];
    }
    cout << endl;
  }

  return 0;
}

bool cmp(string a, string b) {
  string temp = a;
  a += b;
  b += temp;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] > b[i]) {
      return false;
    } else if (a[i] < b[i]) {
      return true;
    }
  }
  return true;
}                                 
