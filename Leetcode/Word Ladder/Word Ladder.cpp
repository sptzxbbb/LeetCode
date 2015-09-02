struct node {
    string word;
    int step;
    node(int s = 0) : step(s) {}
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<node> q;
        set<string> visit;
        node start(1);
        start.word = beginWord;
        q.push(start);
        visit.insert(beginWord);
        // leetcode描述有错, wordDict中其实包含了beginWord和endWord. 但正确的写法时需要把endWord放进去wordDict.
        wordDict.insert(endWord);
        // bfs
        int res = 0;
        int size = beginWord.size();
        while (!q.empty()) {
            node cur = q.front();
            q.pop();
            // find the end word
            if (cur.word == endWord) {
                return cur.step;
            }
            for (int i = 0; i < size; i++) {
                string temp = cur.word;
                for (int j = 0; j < 26; j++) {
                    temp[i] = 'a' + j;
                    if (temp != cur.word &&
                        wordDict.find(temp) != wordDict.end() &&
                        visit.find(temp) == visit.end()) {
                        node n(cur.step + 1);
                        n.word = temp;
                        q.push(n);
                        visit.insert(temp);
                    }
                }
            }
        }
        return res;
    }
};