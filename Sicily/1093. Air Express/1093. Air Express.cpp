#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    void express(void) {
        int w1, r1, w2, r2, w3, r3, r4;
        int count = 0;
        while (cin >> w1) {
            cin >> r1
                >> w2 >> r2
                >> w3 >> r3
                >> r4;
            cout << "Set number " << ++count << ":" << endl;
            int custom;
            while (cin >> custom && custom != 0) {
                int price, add = 0;
                if (custom >= (w3 + 1)) {
                    price = custom * r4;
                } else if (custom >= (w2 + 1)) {
                    price = custom * r3;
                    if ((w3 + 1) * r4 < price) {
                        price = (w3 + 1) * r4;
                        add = (w3 + 1) - custom;
                    }
                } else if (custom >= (w1 + 1)) {
                    price = custom * r2;
                    if ((w2 + 1) * r3 < price) {
                        price = (w2 + 1) * r3;
                        add = (w2 + 1) - custom;
                    }
                    if ((w3 + 1) * r4 < price) {
                        price = (w3 + 1) * r4;
                        add = (w3 + 1) - custom;
                    }
                } else {
                    price = custom * r1;
                    if ((w1 + 1) * r2 < price) {
                        price = (w1 + 1) * r2;
                        add = (w1 + 1) - custom;
                    }
                    if ((w2 + 1) * r3 < price) {
                        price = (w2 + 1) * r3;
                        add = (w2 + 1) - custom;
                    }
                    if ((w3 + 1) * r4 < price) {
                        price = (w3 + 1) * r4;
                        add = (w3 + 1) - custom;
                    }
                }
                cout << "Weight (" << custom << ") has best price $" << price << " (add " << add << " pounds)" << endl;
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution k;
    k.express();
    return 0;
}











