void quicksort(int* arr, int begin, int end) {
  
}

int main(int argc, char *argv[]) {
   int n;
   while (cin >> n) {
     int arr[n];
     for (int i = 0; i < n; ++i) {
       cin >> arr[i];
     }
     quicksort(arr, 0, n - 1);
   }
   return 0;
 }
