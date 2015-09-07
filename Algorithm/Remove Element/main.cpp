#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
	int pos = 0;
	for (int i = 0; i < n; ++i) {
	    if (A[i] != elem) {
		A[pos++] = A[i];
	    }
	}
	return pos;
    }
};



int main(int argc, char *argv[]) {
    Solution s;
    int a[] = {1, 2, 3, 4, 5, 1, 1, 5};
    cout << s.removeElement(a, 8, 1) << endl;;
    return 0;
}
