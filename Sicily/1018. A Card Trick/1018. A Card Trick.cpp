#include <iostream>
#include <string>
#include <vector>
using namespace std;

int helper(string s) {
    int sum = 0;
    char ch = s[0];
    if (ch >= '2' && ch <= '9') {
        sum = ch - '0';
    } else {
        switch (ch) {
            case '1':
                sum = 10;
                break;
            case 'A':
                sum = 1;
                break;
            case 'J':
                sum = 11;
                break;
            case 'Q':
                sum = 12;
                break;
            case 'K':
                sum = 13;
        }
    }
    return sum;
}

bool cmp(string a, string b) {
    if (helper(a) > helper(b)) {
        return true;
    } else if (helper(a) == helper(b)) {
        return a[a.size() - 1] > b[b.size() - 1];
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    int n, numCase = 0;
    cin >> n;
    while (n--) {
        string card[5];
        char suit[5];
        int value[5];
        for (int i = 0; i < 5; i++) {
            cin >> card[i];
            suit[i] = card[i][card[i].size() - 1];
            value[i] = helper(card[i]);
        }
        int a1, a2, a3, a4, a5, diff;
        // find a1 a2
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (suit[i] == suit[j]) {
                    int l = value[i] > value[j] ? i : j;
                    int s = value[i] > value[j] ? j : i;
                    if (value[l] - value[s] > 6) {
                        a1 = s;
                        a2 = l;
                        diff = value[s] + 13 - value[l];
                    } else {
                        a1 = l;
                        a2 = s;
                        diff = value[l] - value[s];
                    }
                    break;
                }
            }
        }
        // find a3 a4 a5
        vector<int> index;
        for (int i = 0; i < 5; i++) {
            if (i != a1 && i != a2) {
                index.push_back(i);
            }
        }
        int min1 = index[0], min2 = index[1] , min3 = index[2];
        if (cmp(card[min1], card[min2])) {
            swap(min1, min2);
        }
        if (cmp(card[min1], card[min3])) {
            swap(min1, min3);
        }
        if (cmp(card[min2], card[min3])) {
            swap(min2, min3);
        }
        if (diff % 3 == 1) {
            a3 = min1;
            if (diff > 3) {
                a4 = min3;
                a5 = min2;
            } else {
                a4 = min2;
                a5 = min3;
            }
        } else if (diff % 3 == 2) {
            a4 = min1;
            if (diff > 3) {
                a3 = min3;
                a5 = min2;
            } else {
                a3 = min2;
                a5 = min3;
            }
        } else if (diff % 3 == 0) {
            a5 = min1;
            if (diff > 3) {
                a3 = min3;
                a4 = min2;
            } else {
                a3 = min2;
                a4 = min3;
            }
        }
        cout << "Problem " << ++numCase << ":";
        cout << " " << card[a1] << " " << card[a2] << " " << card[a3] << " " << card[a4] << " " << card[a5] << endl;
    }
    return 0;
}
