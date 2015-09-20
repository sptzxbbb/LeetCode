#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
    	enum InputType {
    		INVALID,  // 0
    		SPACE,    // 1
    		SIGN,     // 2
    		DIGIT,    // 3
    		DOT,      // 4
    		EXPONENT,  // 5
    		NUM_INPUT
    	};

    	int table[][NUM_INPUT] = {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1     // next states for state 8
        };

    	int state = 0;
    	for (int i = 0; i < s.size(); ++i) {
    		InputType input = INVALID;
    		if (isspace(s[i])) {
    			input = SPACE;
    		} else if (s[i] == '+' || s[i] == '-') {
    			input = SIGN;
    		} else if (isdigit(s[i])) {
    			input = DIGIT;
    		} else if (s[i] == '.') {
    			input = DOT;
    		} else if (s[i] == 'e' || s[i] == 'E') {
    			input = EXPONENT;
    		}
    		state = table[state][input];
    		if (state == -1) {
    			return false;
    		}
    	}
    	return state == 1 || state == 4 || state == 7 || state == 8;
	}
};

int main() {
	Solution k;
	cout << k.isNumber("3") << endl;
}
