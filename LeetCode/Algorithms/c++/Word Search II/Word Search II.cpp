class TrieNode {
public:
    bool isKey;
    TrieNode *sub[26];

// Initialize your data structure here.
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 26; i++) {
            sub[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string word) {
        int size = word.size();
        TrieNode* node = root;
        for (int i = 0; i < size; i++) {
            int index = word[i] - 'a';
            if (NULL == node->sub[index]) {
                node->sub[index] = new TrieNode();
            }
            node = node->sub[index];
        }
        node->isKey = true;
        return;
    }
    // Returns if the word is in the trie.
    bool search(string k) {
        TrieNode* node = root;
        int size = k.size();
        for (int i = 0; i < size; i++) {
            if (node) {
                node = node->sub[k[i] - 'a'];
            } else {
                return false;
            }
        }
        if (node) {
            return node->isKey;
        } else {
            return false;
        }
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int size = prefix.size();
        for (int i = 0 ; i < size; i++) {
            if (node) {
                node = node->sub[prefix[i] - 'a'];
            } else {
                return false;
            }
        }
        if (NULL == node) {
            return false;
        } else {
            return true;
        }
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        if (row == 0) {
            return res;
        }
        int col = board[0].size();
        Trie t;
        for (string word : words) {
            t.insert(word);
        }
        vector<vector<bool> > visit(row, vector<bool>(col, false));
        set<string> exist;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, visit, exist, t, i, j, "");
            }
        }
        for (string word : words) {
            if (exist.find(word) != exist.end()) {
                res.push_back(word);
                exist.erase(word);
            }
        }
        return res;
    }
    void dfs(vector<vector<char> >& board, vector<vector<bool> >& visit, set<string>& exist, Trie& t, int x, int y, string s) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visit[x][y] || !t.startsWith(s)) {
            return;
        }
        s += board[x][y];
        if (t.search(s)) {
            //res.push_back(s);
            exist.insert(s);
        }
        visit[x][y] = true;
        dfs(board, visit, exist, t, x - 1, y, s);
        dfs(board, visit, exist, t, x + 1, y, s);
        dfs(board, visit, exist, t, x, y - 1, s);
        dfs(board, visit, exist, t, x, y + 1, s);
        visit[x][y] = false;
    }
};
