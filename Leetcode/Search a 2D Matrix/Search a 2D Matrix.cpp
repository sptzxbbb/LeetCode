#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = rowSearch(matrix, target, 0, matrix.size() - 1);
        if (-1 == row) {
            return false;
        } else {
            return colSearch(matrix[row], target, 0, matrix[row].size() - 1);
        }
    }

    int rowSearch(vector<vector<int> >& matrix, int target, int start, int end) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (
            (mid < end && matrix[mid][0] <= target && matrix[mid + 1][0] > target) ||
            (mid == end && matrix[mid][0] <= target)
            ) {
            return mid;
        }
        if (matrix[mid][0] > target) {
            return rowSearch(matrix, target, start, mid - 1);
        } else {
            return rowSearch(matrix, target, mid + 1, end);
        }
    }

    bool colSearch(vector<int>& matrix, int target, int start, int end) {
        int mid = (start + end) / 2;
        if (start > end) {
            return false;
        }
        if (matrix[mid] == target) {
            return true;
        }
        if (matrix[mid] > target) {
            return colSearch(matrix, target, start, mid - 1);
        } else if (matrix[mid] < target) {
            return colSearch(matrix, target, mid + 1, end);
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> e1, e2;
    e1.push_back(1);
    e2.push_back(3);
    vector<vector<int> > a;
    a.push_back(e1);
    a.push_back(e2);
    Solution k;
    cout << k.searchMatrix(a, 3);
    return 0;
}


















