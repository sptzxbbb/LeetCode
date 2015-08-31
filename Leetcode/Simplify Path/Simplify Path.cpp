#include <iostream>
#include <vector>
#include <string>
#include <list>

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
                dir.push_back(f[i]);
            }
        }
        list<string>::iterator it = dir.begin();
        string ans;
        while (it != dir.end()) {
            ans += "/" + (*it);
            ++it;
        }
        if (ans.empty()) {
            ans = "/";
        }
        return ans;
    }

    void extraFile(vector<string>& f, string path) {
        string file = "";
        int i = 0, size = path.size();
        while (i < size) {
            while (i < size && path[i] == '/') {
                ++i;
            }
            while (i < size && path[i] != '/') {
                file += path[i];
                ++i;
            }
            if (!file.empty()) {
                f.push_back(file);
                file = "";
            }
        }
        return;
    }
};

int main(int argc, char *argv[])
{
    Solution k;
    string path = "/.../";
    cout << "Output : " << k.simplifyPath(path) << endl;
    return 0;
}
