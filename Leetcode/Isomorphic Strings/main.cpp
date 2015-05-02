#include "cstring"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
	bool occur[256], isMap[256];
	int map[256], length = s.size();
	memset(occur, false, sizeof(occur));
	memset(isMap, false, sizeof(isMap));
	for (int i = 0; i < length; ++i) {
	    // first occurance
	    if (false == occur[s[i]]) {
		occur[s[i]] = true;
		// t[i] have been mapped already
		if (true == isMap[t[i]]) {
 		    return false;
		} else {
		    // t[i] have not been mapped
		    isMap[t[i]] = true;
		    map[s[i]] = t[i];
		}
	    } else {
		if (map[s[i]] != t[i]) {
		    return false;
		}
	    }
	}
	return true;
    }
};
