class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        if (start == end) {
            return res;
        }
        unordered_set<string> current, next, visit;
        unordered_map<string, vector<string> > father;
        current.insert(start);
        bool found = false;
        while (!current.empty() && !found) {
            for (auto &x : current) {
                visit.insert(x);
            }

            for (auto word : current) {
                for (int i = 0; i < word.size(); i++) {
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (word[i] == j) {
                            continue;
                        }
                        string temp = word;
                        temp[i] = j;
                        if (temp == end) {
                            found = true;
                        }
                        if (dict.find(temp) != dict.end() &&
                            visit.find(temp) == visit.end()) {
                            next.insert(temp);
                            father[temp].push_back(word);
                        }

                    }
                }
            }
            current.clear();
            swap(current, next);
        }
        if (found) {
            vector<string> path;
            dfs(res, father, path, start, end);
        }
        return res;
    }
  private:
    void dfs(vector<vector<string> >& res, unordered_map<string ,vector<string> >& father,
             vector<string>& path, string& start, string& now) {
        path.push_back(now);
        if (now == start) {
            res.push_back(path);
            reverse(res.back().begin(), res.back().end());
            path.pop_back();
            return;
        }
        auto pre = father.find(now)->second;
        for (auto& x : pre) {
            dfs(res, father, path, start, x);
        }
        path.pop_back();
    }
};