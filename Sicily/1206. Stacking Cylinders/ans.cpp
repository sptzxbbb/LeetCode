#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct node {
	double x,y;
	bool operator<(const node &b) const {
         return x < b.x;
    }
};

node a[10][10];
int t,n;
int casenum;

double abs(double x) {
	return x < 0.0 ? -x : x;
}

void cal_pos(int i, int j){
	double ang1, ang2;
	ang1 = (a[i - 1][j + 1].y - a[i - 1][j].y) /
            (a[i - 1][j + 1].x - a[i - 1][j].x);
	ang1 = atan(ang1);
	ang2 = sqrt(pow((a[i - 1][j].y - a[i - 1][j + 1].y), 2.0) +
                pow((a[i - 1][j + 1].x - a[i - 1][j].x), 2.0));
	ang2 = acos(ang2 / 4.0);
	a[i][j].x = a[i - 1][j].x + 2 * cos(ang1 + ang2);
	a[i][j].y = a[i - 1][j].y + 2 * sin(ang1 + ang2);
}

int main(int argc, char *argv[]) {
	scanf("%d", &t);
	casenum=0;
	while (t--) {
		++casenum;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &a[0][i].x);
			a[0][i].y=1.0;
		}

		sort(&a[0][0], &a[0][0] + n);
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n - i; ++j) {
				cal_pos(i,j);
			}
		}
	    printf("%d: %.4lf %.4lf\n", casenum, a[n-1][0].x, a[n-1][0].y);
	}
	return 0;
}

// Sample Input

// 5
// 4 1.0 4.4 7.8 11.2
// 1 1.0
// 6 1.0 3.0 5.0 7.0 9.0 11.0
// 10 1.0 3.0 5.0 7.0 9.0 11.0 13.0 15.0 17.0 20.4
// 5 1.0 4.4 7.8 11.2 14.6
// Sample Output

// 1: 6.1000 4.1607
// 2: 1.0000 1.0000
// 3: 6.0000 9.6603
// 4: 10.7000 15.9100
// 5: 7.8000 5.2143
