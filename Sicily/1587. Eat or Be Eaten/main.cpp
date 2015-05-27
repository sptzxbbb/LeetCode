// soj: 1587. Eat or Be Eaten
// Thu Dec 11, 2014--------Shawn Chow
#include "cstdio"
#include "algorithm"

int predator[20001], N;

int search(int e, int left, int right);

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int M, ans = 0, temp;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i) {
      scanf("%d", &predator[i]);
    }
    std::sort(predator, predator + N);

    for (int i = 0; i < M; ++i) {
      scanf("%d", &temp);
      ans += N - (search(temp, 0, N - 1));
    }
    printf("%d\n", ans);
  }
  return 0;
}

int search(int e, int left, int right) {
  int mid = (left + right) / 2;
  if (predator[N - 1] < e) return N;

  while (left <= right) {
    mid = (left + right) / 2;
    if (predator[mid] > e) right = mid - 1;
    else left = mid + 1;
  }
  return right + 1;
}
