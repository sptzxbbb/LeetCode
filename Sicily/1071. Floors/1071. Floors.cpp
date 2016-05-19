#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct recType {
    int x1, x2, y1, y2;
};

bool cmp1(recType r1, recType r2) {
    return (r1.x1 != r2.x1 ? (r1.x1 < r2.x1) : (r1.x2 < r2.x2));
}

bool cmp2(recType r1, recType r2) {
    return (r1.y1 != r2.y1 ? (r1.y1 < r2.y1) : (r1.y2 < r2.y2));
}

void cal(int length, int width, int& maxArea, vector<recType>& r) {
    // set removes duplicates naturally
    set<int> x, y;
    for (int i = 0; i < (int)r.size(); i++) {
        x.insert(r[i].x1);
        x.insert(r[i].x2);
        y.insert(r[i].y1);
        y.insert(r[i].y2);
    }
    if (x.size() <= 2 && y.size() <= 2) {
        maxArea = max(maxArea, length * width);
        return;
    }

    sort(r.begin(), r.end(), cmp1);
    int startX = *(x.begin());
    int endX = *(--x.end());
    x.erase(startX);
    x.erase(endX);
    bool flag;
    // search every possible edge
    for (set<int>::iterator it1 = x.begin(); it1 != x.end(); it1++) {
        flag = true;
        for (int i = 0; i < (int)r.size(); i++) {
            int pos = *it1;
            if (pos > r[i].x1 && pos < r[i].x2) {
                flag = false;
                break;
            }
        }
        if (flag) {
            vector<recType> rl, rr;
            for (int i = 0; i < (int)r.size(); i++) {
                if (r[i].x2 <= *it1) {
                    rl.push_back(r[i]);
                } else {
                    rr.push_back(r[i]);
                }
            }
            cal(*it1 - startX, width, maxArea, rl);
            cal(endX - *it1, width, maxArea, rr);
            return;
        }
    }
    sort(r.begin(), r.end(), cmp2);
    int startY = *(y.begin());
    int endY = *(--y.end());
    y.erase(startY);
    y.erase(endY);
    for (set<int>::iterator it1 = y.begin(); it1 != y.end(); it1++) {
        flag = true;
        for (int i = 0; i < (int)r.size(); i++) {
            int pos = *it1;
            if (pos > r[i].y1 && pos < r[i].y2) {
                flag = false;
                break;
            }
        }
        if (flag) {
            vector<recType> rl, rr;
            for (int i = 0; i < (int)r.size(); i++) {
                if (r[i].y2 <= *it1) {
                    rl.push_back(r[i]);
                } else {
                    rr.push_back(r[i]);
                }
            }
            cal(length, *it1 - startY, maxArea, rl);
            cal(length, endY - *it1, maxArea, rr);
            return;
        }
    }
    maxArea = max(maxArea, length * width);
}

int main(int argc, char *argv[]) {
    int numFloor;
    cin >> numFloor;
    while (numFloor--) {
        int length, width, numTitle;
        cin >> length >> width;
        cin >> numTitle;
        vector<recType> r(numTitle);
        for (int i = 0; i < numTitle; i++) {
            cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
        }
        int maxArea = 0;
        cal(length, width, maxArea, r);
        cout << maxArea << endl;
    }
    return 0;
}
