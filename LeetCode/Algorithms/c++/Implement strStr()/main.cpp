#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (0 == needle.size()) return 0;
        vector<int> next;
		getNext(needle, next);
        int i = 0, j = 0;
        int pos = -1, size1 = haystack.size(), size2 = needle.size();
        while (i < size1) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
                if (j == size2) {
                    pos = i - size2;
                    break;
                }
            } else {
                if (0 == j) {
                    ++i;
                } else {
                    j = next[j];
                }
            }
        }
        return pos;
    }
    void getNext(string s, vector<int>& next) {

        next.resize(s.size());
        next[0] = -1;
        int i = 0, j = -1;

        while (i != s.size() - 1) {
            if (-1 == j || s[i] == s[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution k;
    string s1 = "mississippi", s2 = "pi";
    cout << k.strStr(s1, s2) << endl;
    return 0;
}
