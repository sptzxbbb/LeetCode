class Solution {
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        string line;
        vector<string> res;
        for (int i = 0; i < size; i++) {
            if (line.empty()) {
                line += words[i];
            } else {

            }
            if (i == size - 1) {
                
            }
        }
        return res;
    }
}