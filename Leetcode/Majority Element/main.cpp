#include "map"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution { // hash table
  public:
    int majorityElement(vector<int> &num) {
        map<int, int> count;
        for (int i = 0; i < num.size(); ++i) {
            ++count[num[i]];
            if (count[num[i]] > num.size() / 2) return num[i];
        }
    }
};

class Solution2 {  // sort
  public:
    int majorityElement(vector<int> &num) {
        vector<int>::iterator it1 = num.begin(), it2 = num.end();
        sort(it1, it2);
        return num[num.size() / 2];

    }
};

class Solution3 {  // Moore Voting
  public:
    int majorityElement(vector<int> &num) {
        int elem, count = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (0 == count) {
                elem = num[i];
                ++count;
            } else {
                if (elem == num[i]) ++count;
                else --count;
            }
        }
        return elem;
    }
};


int main(int argc, char *argv[]) {
    vector<int> a;
    for (int i = 0; i < 5; ++i) {
        a.push_back(3);
    }
    for (int i = 0; i < 9; ++i) {
        a.push_back(5);
    }
    Solution3 k;
    cout << k.majorityElement(a) << endl;
    return 0;
}


