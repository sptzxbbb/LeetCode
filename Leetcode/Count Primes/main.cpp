#include "cstring"
#include "iostream"
using namespace std;

const int Max = 1500000;

class Solution {
public:
    Solution() {
	init = false;
	memset(table, 1, sizeof(table));
    }

    int countPrimes(int n) {
	if (false == init) {
	    maketable();
	    init = true;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
	    if (true == table[i]) {
		++ans;
	    }
	}
	return ans;
    }

    void maketable() {
	table[0] = false;
	table[1] = false;
	for (int i = 2; i <= Max; ++i) {
	    if (true == table[i] && (i * i <= Max)) {
		int temp = 2 * i;
		while (temp <= Max) {
		    table[temp] = false;
		    temp += i;
		}
	    }
	}
    }

private:
    bool init;
    bool table[Max];
};

int main(int argc, char *argv[]) {
    Solution prime;
    cout << prime.countPrimes(0) << endl;
    return 0;
}


