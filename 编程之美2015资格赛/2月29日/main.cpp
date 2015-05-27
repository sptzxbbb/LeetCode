#include "iostream"
#include "string"
using namespace std;

bool IsLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	int t, n = 0;
	cin >> t;
	while (t--) {
		char temp;
		string month1, month2;
		int day1,  year1, day2, year2;
		int ans = 0;
		cin >> month1 >> day1 >> temp >>year1;
		cin >> month2 >> day2 >> temp >> year2;
		
		// the interval year
		for (int i = year1 + 1; i < year2; ++i) {
			if (IsLeapYear(i)) ++ans;
		}
		
		if (year2 > year1) {
			if (IsLeapYear(year1)) {
				if ("January" == month1 || ("February" == month1 && day1 <= 29))
					++ans;
			}
			if (IsLeapYear(year2)) {
				if (month2 != "January") {
					if (month2 == "February") {
						if (day2 == 29) ++ans;
					} else {
						++ans;
					}
				}
			}
		} else {
			// year1 == year2
			if (IsLeapYear(year1)) {
				if ("January" == month1 || ("February" == month1 && day1 <= 29)) {
					if ("January" != month2) {
						if (month2 == "February") {
							if (day2 == 29) ++ans;
						} else {
							++ans;
						}
					}
				}
			}
		}
		cout << "Case #" << ++n << ": " << ans << endl;
	}
	return 0;
}
