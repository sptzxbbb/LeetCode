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
        int wordSize = words[0].size();
        for (int i = 0; i <= (int)s.size() - wordsSize * wordSize; i++) {
            sCount.clear();
            for (int j = 0; j < wordsSize; j++) {
                string subWord = s.substr(i + j * wordSize, wordSize);
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

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.size(), wSize, wordL, i, j, count, start ;
        vector<int> res;
        if(!(wSize=words.size()) || !(wordL = words[0].size()) || sLen < wSize*wordL) return res;
        unordered_map<string, int> dict;
        //build dictory
        for(i=0;i<wSize; ++i) ++dict[words[i]];

        for(j=0; j<wordL;++j) // go through each possible starting point of a word sequence
        {
            for(i=j, start = j, count=0; i<=sLen-wordL; i+=wordL) // go through each word sequence, remember to reset count and start
            {
                if(dict.count(s.substr(i, wordL))==0)
                {// if it is not a word in words, reset start, count and dict
                    while(start<i)
                    {
                        ++dict[s.substr(start, wordL)];
                        start +=wordL;
                    }
                    start = i+wordL;
                    count = 0;
                    continue;
                }
                if(--dict[s.substr(i, wordL)] < 0)
                {// if it is a word in words, but we already found such words, then we need to move forward start to exclude such extra word
                    while(dict[s.substr(i, wordL)]<0)
                    {
                        ++dict[s.substr(start, wordL)];
                        start +=wordL;
                        --count;
                    }
                }
                if(++count == wSize)
                { // otherwise, we found a valid word in words, update count and if we find all the words, then save the results, and move start
                    res.push_back(start);
                    ++dict[s.substr(start, wordL)];
                    start +=wordL;
                    --count;
                }
            }
            //recover dict for the next word sequence
            while(start<i) {++dict[s.substr(start, wordL)]; start+=wordL;}
        }
    }
};