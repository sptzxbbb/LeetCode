#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

struct point {
    double x, y;
    bool operator<(const point& b) const {
        return x < b.x;
    }
};

void cal(int i, vector<point>& v) {
    double ang1, ang2;
    ang1 = atan((v[i + 1].y - v[i].y) / (v[i + 1].x - v[i].x));
    ang2 = sqrt(pow((v[i + 1].y - v[i].y), 2.0) +
                pow((v[i + 1].x - v[i].x), 2.0));
    ang2 = acos(ang2 / 4.0);
    v[i].x = v[i].x + 2 * cos(ang1 + ang2);
    v[i].y = v[i].y + 2 * sin(ang1 + ang2);
}

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n && n != 0) {
        vector<point> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].x;
            v[i].y = 1.0;
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                cal(j, v);
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(4)
             << v[0].x << " " << v[0].y << endl;
    }
    return 0;
}
