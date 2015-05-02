#include "iostream"
#include "string"
#include "sstream"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
	string s1 = "1";
	for (int j = 1; j < n; ++j) {
	    string s2 = "";
	    char digit = s1[0];
	    int count = 1; 
	    for (int i = 0; i < s1.size(); ++i) {
		//  tranformer count into a string
		stringstream ss;
		if (i != s1.size() - 1) {
		    if (s1[i] == s1[i + 1]) {
			++count;
		    } else {
			ss << count;
			s2 += ss.str();
			s2 += digit;
			digit = s1[i + 1];
			count = 1;
		    }
		} else {
		    //  process the last digit
		    ss << count;
		    s2 += ss.str();
		    s2 += digit;
		}
	    }
	    s1 = s2;
	}
	return s1;
    }
};

int main(int argc, char *argv[]) {
    Solution a;
    for (int i = 1; i < 8; ++i) {
	cout << a.countAndSay(i) << endl;
    }


    return 0;
}
