#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int add(int c[81],string& str) {
  for (int i = 0; i < str.size() / 2; i++)
    swap(str[i], str[str.size() - 1 - i]);
  
  for(int i = 0; i < str.size(); i++) {
    c[i] += (str[i] - '0');
    c[i + 1] += c[i] / 2;
    c[i] = c[i] % 2;
  }
  
  for(int i = str.size(); i <= 80; i++) {
    c[i + 1] += c[i] / 2;
    c[i] = c[i] % 2;
  }
  return 0;
}

int main() {
  int cs;
  cin >> cs;
  for (int i = 1; i <= cs; i++) {
    string a,b;
    cin >> a >> b;
    cout << i << " ";
    int c[81] = {0};
    add(c, a);
    add(c, b);
    int j;
    for(j = 80; j >= 0; j--)
      if(c[j] != 0) break;
      
    if(j <= 0) j=0;
      
    for(; j >= 0; j--) cout << c[j];
    
    cout << endl;
  }
  return 0;
}                                 
