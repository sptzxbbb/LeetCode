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
            if (rst == "0") rst = "";
            rst += to_string(a);
        }
        return rst;
    }
    static bool cmp(int a, int b) {
        string str1 = to_string(a);
        string str2 = to_string(b);
        string sum1 = str1 + str2;
        string sum2 = str2 + str1;
        //return sum1.compare(sum2) > 0 ? true : false;
        cout << sum1 << endl;
        cout << sum2 << endl;
        int size = sum1.size();
        for (int i = 0; i < size; i++) {
            if (sum1[i] > sum2[i]) return false;
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
