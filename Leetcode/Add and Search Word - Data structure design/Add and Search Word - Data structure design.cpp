struct node {
    bool isWord;
    node *next[26];
    // Initialize a node
    node() : isWord(false) {
        for (int i = 0; i < 27; i++) {
            next[i] = NULL;
        }
    }
};

class WordDictionary {
  public:
    WordDictionary() {
        start = new node();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        node* p = start;
        for (auto a : word) {
            int i = a - 'a';
            if (!p->next[i]) {
                p->next[i] = new node();
            }
            p = p->next[i];
        }
        p->isWord = true;
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(start, word, 0);
    }

    bool searchWord(node* root, string& word, int pos) {
        if (pos == word.size()) {
            return root->isWord;
        }
        if (word[pos] == '.') {
            for (auto a : root->next) {
                if (a && searchWord(a, word, pos + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return root->next[word[pos] - 'a'] && searchWord(root->next[word[pos] - 'a'], word, pos + 1);
        }
    }

    ~WordDictionary() {
        release(start);
    }

    void release(node* root) {
        for (int i = 0; i < 27; i++) {
            if (root->next[i] != NULL) {
                release(root->next[i]);
            }
        }
        delete root;
    }

  private:
    node *start;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");