class Solution {
  public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int srcLen = beginWord.size(), destLen = endWord.size(), dictSize = wordDict.size();
        if((srcLen != destLen) || !srcLen || !dictSize) return 0;
        // words that never visited before
        unordered_set<string> unusedWords = wordDict;
        unordered_set<string> activeWords[3];
        // activeWords[startSet] is an unordered_set that includes all the nodes we are going to expand with BFS.
        // activeWords[endSet] is an unordered_set that includes all the ending nodes from the other side (or direction)
        // activeWords[nextSet] is an unordered_set that saves the ending nodes of all the BFS expanded paths from activeWords[startSet]
        int startSet = 0, endSet = 1, nextSet = 2, curDepth = 2, i;
        char tempC, j;
        activeWords[startSet].insert(beginWord);
        activeWords[endSet].insert(endWord);
        unusedWords.erase(beginWord);
        unusedWords.erase(endWord);
        // do BFS on startSet
        while(!activeWords[startSet].empty()) {
            for(auto it : activeWords[startSet]) {
                for(i = 0; i < srcLen; ++i) {
                    for(tempC = it[i], j = 'a'; j <= 'z'; ++j) {
                        if(tempC == j) continue;
                        it[i] = j;
                        // if the new word is in the endSet, then we find a path
                        if(activeWords[endSet].count(it) > 0) {
                            return curDepth;
                        }
                        // otherwise, if it is a new word that has never been visited
                        if(unusedWords.count(it)) {
                            activeWords[nextSet].insert(it);
                            unusedWords.erase(it);
                        }
                    }// FOR j
                    it[i] = tempC;
                } // FOR i
            } //FOR it
            ++curDepth;
            // swap the startSet and the nextSet
            swap(startSet, nextSet);
            // if needed, switch the search direction
            if(activeWords[startSet].size() > activeWords[endSet].size()) swap(startSet, endSet);
            activeWords[nextSet].clear();
        }
        return 0;
    }
};