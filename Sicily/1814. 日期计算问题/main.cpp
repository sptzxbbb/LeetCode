// soj: 1814. 日期计算问题
// Sun Nov 30, 2014--------Shawn Chow
#include "string"
#include "iostream"
using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeap(int a) {
  if (a % 400 == 0) return true;
  if (a % 4 == 0 && a % 100 != 0) return true;
  return false;
}

class date {
public:
  
  date(string s) {
    year = (s[0] - '0') * 1000 + (s[1] - '0') *
      100 + (s[2] - '0') * 10 + (s[3] - '0');
    
    month = (s[5] - '0') * 10 + (s[6] - '0');
    
    day = (s[8] - '0') * 10 + (s[9] - '0');
    
    sum = 0;
      
    for (int i = 0; i < year; ++i) {
      if (IsLeap(i)) sum += 366;
      else sum += 365;
    }

    if (IsLeap(year)) months[2] = 29;
    else months[2] = 28;
    
    for (int i = 0; i < month; ++i) {
      sum += months[i];
    }
    
    sum += day;
  }
  
  ~date() {}

  bool operator>(const date& n) {
    if (year > n.year) return true;
    else if (year == n.year) {
      if (month > n.month) return true;
      else if (month == n.month) {
	if (day > n.day) return true;
	else if (day == n.day) return true;
	else return false;
      } else return false;
    } else return false;
  }

  bool operator<(const date& n) {
    return !(*this > n);
  }
  
  int operator-(const date& n) {
    return sum - n.sum;
  }
  
private:
  int year;
  int month;
  int day;
  int sum;
};



int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    date d1(s1), d2(s2);
    if (d1 > d2) cout << (d1 - d2) << endl;
    else cout << (d2 - d1) << endl;
  }

  return 0;
}
