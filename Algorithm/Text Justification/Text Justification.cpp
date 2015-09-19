#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, line;
        int length = 0;
        for (int i = 0; i < (int)words.size(); i++) {
            if ((length + (int)words[i].size() + (int)line.size()) <= maxWidth) {
                // add the string into current line
                length += words[i].size();
                line.push_back(words[i]);
            } else {
                // generate the formated line and prepare next line
                string s;
                int extra = 0;
                int space = maxWidth - length;
                int sum = space;
                if (line.size() > 1) {
                    extra = (maxWidth - length) % (line.size() - 1);
                    space = (maxWidth - length) / (line.size() - 1);
                }
                for (int j = 0; j < (int)line.size(); j++) {
                    s += line[j];
                    if (sum > 0) {
                        string temp(space, ' ');
                        sum -= space;
                        s += temp;
                        if (extra > 0) {
                            s += ' ';
                            --extra;
                            --sum;
                        }
                    }
                }
                res.push_back(s);
                line.clear();
                line.push_back(words[i]);
                length = words[i].size();
            }
        }
        // deal with the last line
        string s;
        int space = maxWidth - length;
        for (string word : line) {
            s += word;
            if (space > 0) {
                s += ' ';
                --space;
            }
        }
        string temp(space, ' ');
        s += temp;
        res.push_back(s);
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<string> words;
    // words.push_back("What");
    // words.push_back("must");
    // words.push_back("be");
    // words.push_back("shall");
    // words.push_back("be.");
    words.push_back("");
    int L = 0;
    Solution k;
    vector<string> ans = k.fullJustify(words, L);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
