// soj: 2501. 算算式
// Thu Dec 18, 2014--------Shawn Chow
#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char *argv[]) {
    int n, k, f[9902], ans = 0;
    cin >> n >> k;
    f[1] = n % 9901;
    for (int i = 2; i < 9901 && i <= k; i++) {
        f[i] = (n * f[i - 1] + f[1]) % 9901;
    }
    if (k > 9900) {
        ans += (f[9900] * (k / 9900)) % 9901;
    }
    ans += f[k % 9900] % 9901;
    cout << ans << endl;
    return 0;
}