#include <algorithm>
using namespace std;

void bubbleSort(double list[], int size) {
    for (int i = 1; i <= size - 1; i++) {
        for (int j = 0; j < size - i; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
    return;
}
