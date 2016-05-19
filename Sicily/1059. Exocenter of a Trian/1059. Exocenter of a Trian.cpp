#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1E-6;
const double INF = 1E+15;
const double PI = 3.141592654;

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Point& operator+(const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y);
    }
};

struct Line {
    double k, b;
    Line() {}
    Line(const Point& p1, const Point& p2) {
        if (fabs(p1.x - p2.x) < EPS) {
            k = INF;
            b = p1.x;
        } else {
            k = (p1.y - p2.y) / (p1.x - p2.x);
            b = p1.y - k * p1.x;
        }
    }
};

Point rotate(const Point& v, double angle) {
    Point res;
    res.x = v.x * cos(angle) - v.y * sin(angle);
    res.y = v.x * sin(angle) + v.y * cos(angle);
    return res;
}

Point middle(const Point& p1, const Point& p2) {
    return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

Point intersect(const Line& l1, const Line& l2) {
    Point p;
    if (l1.k == INF) {
        p.x = l1.b;
        p.y = l2.k * p.x + l2.b;
    } else if (l2.k == INF) {
        p.x = l2.b;
        p.y = l1.k * p.x + l1.b;
    } else {
        p.x = (l1.b - l2.b) / (l2.k - l1.k);
        p.y = l1.k * p.x + l1.b;
    }
    return p;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    while (n--) {
        Point A, B, C;
        cin >> A.x >> A.y;
        cin >> B.x >> B.y;
        cin >> C.x >> C.y;
        Point D, G, L, E, J, M, O;
        D = rotate(B - A, PI / 2) + A;
        G = rotate(C - A, -PI / 2) + A;
        L = middle(D, G);
        E = rotate(A - B, -PI / 2) + B;
        J = rotate(C - B, PI / 2) + B;
        M = middle(E, J);
        O = intersect(Line(L, A), Line(M, B));
        double x = fabs(O.x) < EPS ? 0 : O.x;
        double y = fabs(O.y) < EPS ? 0 : O.y;
        cout << fixed << setprecision(4) << x << ' ' << y << endl;
    }
    return 0;
}
