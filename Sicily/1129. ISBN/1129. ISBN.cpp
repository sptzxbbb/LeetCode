#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    while (cin >> s) {
        int weight = 10, sum = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (isdigit(s[i])) {
                sum += weight * (s[i] - '0');
                --weight;
            }
        }
        int check_digit = (11 - sum % 11) % 11;
        cout << s << "-";
        if (check_digit == 10) {
            cout << "X" << endl;
        } else {
            cout << check_digit << endl;
        }
    }
    return 0;
}
