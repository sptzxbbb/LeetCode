class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int two = 0;
        for (auto i : nums) {
            two ^= i;
        }
        int index = findFirstBit1(two);
        int num1 = 0, num2 = 0;
        for (auto i : nums) {
            if (isBit1(i, index)) {
                num1 ^= i;
            } else {
                num2 ^= i;
            }
        }
        vector<int> res;
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }

    int findFirstBit1(int num) {
        int index = 0;
        while ((num & 1) == 0) {
            ++index;
            num >>= 1;
        }
        return index;
    }

    bool isBit1(int num, int index) {
        num >>= index;
        return num & 1;
    }

};