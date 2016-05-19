#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int maxCost, lenProcess;
    bool first = false;
    while (cin >> maxCost >> lenProcess) {
        vector<int> removal(lenProcess);
        for (int i = 0; i < lenProcess; i++) {
            cin >> removal[i];
        }
        char command;
        int policy = 1, cost, count = 0, index = 0;
        vector<int> v, res;
        while (cin >> command && command != 'e') {
            if (command == 'a') {
                cin >> cost;
                v.push_back(cost);
            } else if (command == 'r') {
                if (policy == 1) {
                    sort(v.begin(), v.end(), greater<int>());
                } else {
                    sort(v.begin(), v.end());
                }
                ++count;
                if (index < (int)removal.size() && count == removal[index]) {
                    res.push_back(v[v.size() - 1]);
                    ++index;
                }
                v.pop_back();
            } else if (command == 'p') {
                cin >> policy;
            }
        }
        if (!first) {
            first = true;
        } else {
            cout << endl;
        }
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
