#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> f;
        extraFile(f, path);
        list<string> dir;
        for (int i = 0; i < (int)f.size(); i++) {
            if (f[i] == ".") {
                continue;
            } else if (f[i] == "..") {
                if (!dir.empty()) {
                    dir.pop_back();
                }
            } else {
                dir.push_back(f[i] + "/");
            }
        }

        list<string>::iterator it = dir.begin();
        string ans = "/";
        while (it != dir.end()) {
            ans += (*it);
            ++it;
        }
        if (ans.size() > 1) {
            ans.pop_back();
        }
        return ans;
    }

    void extraFile(vector<string>& f, string path) {
        string file = "";
        int i = 1, size = path.size();
        while (i < size) {
            if (path[i] != '/') {
                file += path[i];
                ++i;
            } else {
                f.push_back(file);
                file = "";
                while (i < size && path[i] == '/') {
                    ++i;
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution k;
    string path = "/../";
    cout << "Input : " << path << endl;
    cout << "Output : " << k.simplifyPath(path) << endl;

    path = "/a/./b/../../c/";
    cout << "Input : " << path << endl;
    cout << "Output : " << k.simplifyPath(path) << endl;

    path = "/home//foo/";
    cout << "Input : " << path << endl;
    cout << "Output : " << k.simplifyPath(path) << endl;

    path = "/home/shawn/../";
    cout << "Input : " << path << endl;
    cout << "Output : " << k.simplifyPath(path) << endl;
    return 0;
}
