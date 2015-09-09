vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> splitVec;
        split(s, ' ',  splitVec);
        s = "";
        for (int i = splitVec.size() - 1; i >= 0; --i) {
            if (s != "" && splitVec[i] != "")
                s.append(" ");
            s.append(splitVec[i]);
        }
    }
};