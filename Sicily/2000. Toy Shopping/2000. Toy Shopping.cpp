#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct toy {
    int index;
    int price;
    double Metric;
    toy(int i, int p, double M) : index(i), price(p), Metric(M) {}
};

bool cmp(toy t1, toy t2) {
    return t1.Metric > t2.Metric;
}

int main(int argc, char *argv[]) {
    int N, count = 0;
    vector<toy> v;
    cin >> N;
    while (N--) {
        int joy, price;
        cin >> joy >> price;
        double Metric;
        Metric = (double)joy / (double)price;
        toy t(++count, price, Metric);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].price + v[1].price + v[2].price << endl;
    for (int i = 0; i < 3; i++) {
        cout << v[i].index << endl;
    }

    return 0;
}
