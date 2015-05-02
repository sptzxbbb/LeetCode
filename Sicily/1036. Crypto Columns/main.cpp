// soj: 1036. Crypto Columns
// Sun Nov 30, 2014--------Shawn Chow
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

struct node {
  char c;
  int o;
};

bool cmp(node a, node b);
string keyword, ctext;

int main(int argc, char *argv[]) {
  cin >> keyword;
  while (keyword != "THEEND") {
    cin >> ctext;
    int col, row, size = keyword.size();
    col = size;
    row = ctext.size() / col;
    char decipher[row][col];
    node key[size];
    
    for (int i = 0; i < size; ++i) {
      key[i].c = keyword[i];
      key[i].o = i;
    }

    stable_sort(key, key + size, cmp);
    int count = 0;
    for (int i = 0; i < col; ++i) {
      for (int j = 0; j < row; ++j) {
       	decipher[j][key[i].o] = ctext[count++];
      }
    }

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
	cout << decipher[i][j];
      }
    }
    
    cout << endl;
    cin >> keyword;
  }
  return 0;
}

bool cmp(node a, node b) {
  if (a.c < b.c) return true;
  else return false;
}
