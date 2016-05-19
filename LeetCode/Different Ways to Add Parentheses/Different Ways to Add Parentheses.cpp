class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            if ('+' == input[i] || '-' == input[i] || '*' == input[i]) {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                int leftSize = left.size();
                int rightSize = right.size();
                for (int j = 0; j < leftSize; j++) {
                    for (int k = 0; k < rightSize; k++) {
                        switch(input[i]) {
                            case '+':
                                res.push_back(left[j] + right[k]);
                                break;
                            case '-':
                                res.push_back(left[j] - right[k]);
                                break;
                            case '*':
                                res.push_back(left[j] * right[k]);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};