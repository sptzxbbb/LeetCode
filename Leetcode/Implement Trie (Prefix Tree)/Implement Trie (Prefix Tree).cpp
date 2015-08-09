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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");