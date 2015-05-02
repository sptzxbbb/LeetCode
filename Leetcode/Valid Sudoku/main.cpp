class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[10], column[10], subbox[10];
	int num1, num2;
	// row check and column check
	for (int i = 0; i < 9; ++i) {
	    memset(row, 0, sizeof(row));
	    memset(column, 0, sizeof(column));
	    for (int j = 0; j < 9; ++j) {
		num1 = board[i][j];
		num2 = board[j][i];
		if ('.' != num1) {
		    num1 -= '0';
		    if (false == row[num1]) {
			row[num1] = true;
		    } else {
			return false;
		    }
		}
		if ('.' != num2) {
		    num2 -= '0';
		    if (false == column[num2]) {
			column[num2] = true;
		    } else {
			return false;
		    }
		}
	    }
	}
	// sub-boxes check
	int index1, index2;
	for (int k = 0; k < 9; ++k) {
	    memset(subbox, 0, sizeof(subbox));
	    index1 = 3 * (k / 3);
	    index2 = 3 * (k % 3);
	    for (int i = index1; i < index1 + 3; ++i) {
		for (int j = index2; j < index2 + 3; ++j) {
		    num1 = board[i][j];
		    if ('.' != num1) {
			num1 -= '0';
			if (false == subbox[num1]) {
			    subbox[num1] = true;
			} else {
			    return false;
			}
		    }
		}
	    }
	}
	return true;
    }
};
