class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > anagrams;
        int size = strs.size();
        for (int i = 0; i < size; i++) {
            string signature = strs[i];
            sort(signature.begin(), signature.end());
            map<string, vector<string> >::iterator it = anagrams.find(signature);

            if (it == anagrams.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                anagrams[signature] = v;
            } else {
                it->second.push_back(strs[i]);
            }
        }
        vector<vector<string> > res;
        map<string, vector<string> >::iterator it = anagrams.begin();
        map<string, vector<string> >::iterator it2 = anagrams.end();
        while (it != it2) {
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
            ++it;
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string> > anagrams;
        for (auto m : mp) {
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};