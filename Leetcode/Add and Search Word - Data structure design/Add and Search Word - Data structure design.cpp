

struct node {
    char c;
    node *next[27];
    node(char ch = 0 ) {
        ch = c;
        for (int i = 0; i < 27; i++) {
            next[i] = NULL;
        }
    }
};



class WordDictionary {
  public:

    WordDictionary() {
        start = new node('.');
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        int size = word.size();
        if (size == 0) {
            return;
        }
        node *cur = start, *next;
        for (int i = 0; i < size; i++) {
            if (word[i] == '.') {
                next = cur->next[26];
            } else {
                next = cur->next[word[i] - 'a'];
            }
            if (next == NULL) {
                next = new node(word[i]);
            }
            cur = next;
        }
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchFirstLetter(start, word);
    }

    bool searchFirstLetter(node* root, string subWord) {
        char ch = subWord[0];
        vector<node*> candidate;
        if (ch == '.') {
            for (int i = 0; i < 27; i++) {
                if (root->next[i] != NULL) {
                    candidate.push_back(root->next[i]);
                }
            }
        } else {
            if (root->next[ch - 'a'] != NULL) {
                candidate.push_back(root->next[ch - 'a']);
            }
        }
        if (candidate.empty()) {
            return false;
        } else {
            if (subWord.size() == 1) {
                return true;
            } else {
                // dfs
                for (int i = 0; i < candidate.size(); i++) {
                    if (searchFirstLetter(candidate[i], subWord.substr(1, subWord.size() - 1))) {
                        return true;
                    }
                }
            }
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