// soj: 1298. 数制转换
// Sun Nov 30, 2014--------Shawn Chow

#include "iostream"
#include "string"
#include "stack"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    char arr[] = "012";
    string s = "";
    stack<char> dig;
    bool negative = false;
    if (n < 0) {
      negative = true;
      n = -n;
    }
    
    do {
      dig.push(arr[n % 3]);
      n /= 3;
    } while (n != 0);

    while (!dig.empty()) {
      s += dig.top();
      dig.pop();
    }
    
    for (int i = s.size() - 1; i > 0; --i) {	       
      if (s[i] == '2') {			       
    	s[i] = '-';				       
    	++s[i - 1];				       
      } else if (s[i] == '3') {		       
    	s[i] = '0';				       
    	++s[i - 1];				       
      }				       
    }
    
    if (s[0] == '2') {
      s[0] = '-';				       
      s = "1" + s;
    } else if (s[0] == '3') {		       
      s[0] = '0';				       
      s = "1" + s;
    }					       
    						       
    if (negative) {				       
      for (int i = 0; i < s.size(); ++i) {	       
    	if (s[i] == '1') s[i] = '-';		       
    	else if (s[i] == '-') s[i] = '1';	       
      }					       
    }					       
    

    
    cout << s << endl;
  }
  return 0;
}


//  122  
//  13-
