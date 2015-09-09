#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string rst;
        for (int a : nums) {
            rst += to_string(a);
        }
        return rst[0] == '0' ? "0" : rst;
    }
    static bool cmp(int a, int b) {
        string str1 = to_string(a);
        string str2 = to_string(b);
        string sum1 = str1 + str2;
        string sum2 = str2 + str1;
        //return sum1 > sum2;
        int size = sum1.size();
        for (int i = 0; i < size; i++) {
            if (sum1[i] != sum2[i]) {
                if (sum1[i] > sum2[i]) return false;
                else return true;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    Solution k;
    cout << k.largestNumber(v) << endl;
    return 0;
}
