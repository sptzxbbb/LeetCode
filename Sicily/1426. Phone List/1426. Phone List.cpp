#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
    bool isKey;
    TrieNode *sub[10];

// Initialize your data structure here.
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 10; i++) {
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
            int index = word[i] - '0';
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
                node = node->sub[k[i] - '0'];
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

    // Returns if the word is a prefix in the trie.
    bool isPrefix(string k) {
        TrieNode* node = root;
        int size = k.size();
        for (int i = 0; i < size; i++) {
            if (node) {
                node = node->sub[k[i] - '0'];
            }
        }
        if (node && node->isKey) {
            for (int i = 0; i < 10; i++) {
                if (node->sub[i]) {
                    return true;
                }
            }
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int size = prefix.size();
        for (int i = 0 ; i < size; i++) {
            if (node) {
                node = node->sub[prefix[i] - '0'];
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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        Trie t;
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            t.insert(v[i]);
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (t.isPrefix(v[i])) {
                ans = false;
                break;
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
