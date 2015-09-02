class Solution {
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordsSize = words.size();
        if (wordsSize == 0) {
            return res;
        }
        map<string, int> wordCount;
        for (int i = 0; i < wordsSize; i++) {
            ++wordCount[words[i]];
        }
        map<string, int> sCount;
        int wordLen = words[0].size();
        for (int i = 0; i <= (int)s.size() - wordsSize * wordLen; i++) {
            sCount.clear();
            for (int j = 0; j < wordsSize; j++) {
                string subWord = s.substr(i + j * wordLen, wordLen);
                if (wordCount.find(subWord) != wordCount.end()) {
                    ++sCount[subWord];
                    if (sCount[subWord] > wordCount[subWord]) {
                        break;
                    }
                    if (j == wordsSize - 1) {
                        res.push_back(i);
                    }
                } else {
                    break;
                }
            }
        }
        return res;
    }
};


// We can leverage the fact that the strings in words have the same length to speed up our algorithm.
// We can divide all the possible starting points (i.e. 0..sLen-1) into wordL sequences and the i-th sequence is (i, i+wordL, i+2*wordL, ...) (I=0..wordL-1).
// Each time we scan one sequence (for j loop). First, we need to build a dictionary based on words and unordered_map is used to simplify look-up operation (key is string, value is count).
// Then for each sequence starting at i, we check if s[i..i+wordL-1] is a word in dict, if no (which means it is not a word in words), then we reset count (the number of words we found in the current window starting at start), and move start to i+wordL to skip the current word and also we need to recover dict.
// If s[i..i+wordL-1] is a word in dict, then we check if we already found all such words before in the current window (i.e. --dict[s.substr(i, wordL)] < 0). If so, the current one is a redundant one, then we have to move forward start to remove one occurence of the current word (i.e. to make dict[s.substr(i, wordL)] == 0) so that the current word can be included in the window.
// We also need to update count accordingly.
// If we find all the words in the current window ( i.e. (++count == wSize)), then we save start to res and move start to remove one occurence of the current word to continue the search. We repeat the above process for each word sequence (i.e. each i). remember after each i iteration, we need to recover dict.

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.size(), wSize, wordL, i, j, count, start;
        vector<int> res;
        if(!(wSize=words.size()) ||
           !(wordL = words[0].size()) ||
           sLen < wSize*wordL) return res;

        unordered_map<string, int> dict;
        //build dictionary
        for(i=0;i<wSize; ++i) ++dict[words[i]];
        // go through each possible starting point of a word sequence
        for(j=0; j<wordL;++j) {
            // go through each word sequence, remember to reset count and start
            for(i=j, start = j, count=0; i<=sLen-wordL; i+=wordL) {
                // if it is not a word in words, reset start, count and dict
                if(dict.count(s.substr(i, wordL))==0) {
                    while(start<i) {
                        ++dict[s.substr(start, wordL)];
                        start +=wordL;
                    }
                    start = i+wordL;
                    count = 0;
                    continue;
                }
                // if it is a word in words, but we already found such words, then we need to move forward start to exclude such extra word
                if(--dict[s.substr(i, wordL)] < 0) {
                    while(dict[s.substr(i, wordL)]<0)
                    {
                        ++dict[s.substr(start, wordL)];
                        start +=wordL;
                        --count;
                    }
                }
                // otherwise, we found a valid word in words, update count and if we find all the words, then save the results, and move start
                if(++count == wSize) {
                    res.push_back(start);
                    ++dict[s.substr(start, wordL)];
                    start +=wordL;
                    --count;
                }
            }
            //recover dict for the next word sequence
            while(start<i) {
                ++dict[s.substr(start, wordL)]; start+=wordL;
            }
        }
    }
};