#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

int main(int argc, char *argv[]) {
    vector<int> a;
    string s = "abcabcacab";
    getNext(s, a);
    return 0;
}

