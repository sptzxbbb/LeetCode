class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string IP = "";
        if (s.size() > 12) {
            return res;
        }
        dfs(s, 0, IP, 0, res);
        return res;
    }
    void dfs(string& s, int pos, string& IP, int count, vector<string>& res) {
        if (pos == s.size() && count == 4) {
            res.push_back(IP);
            return;
        }
        int size = s.size();
        for (int i = pos; i < pos + 3 && i < size; i++) {
            string subIP = s.substr(pos, i - pos + 1);
            if (subIP[0] == '0' && subIP.size() > 1) {
                continue;
            }
            int k = atoi(subIP.c_str());
            if (k < 256) {
                string temp = IP;
                IP += (count == 0 ? "" : ".");
                IP += subIP;
                dfs(s, i + 1, IP, count + 1, res);
                IP = temp;
            }
        }
        return;
    }
};