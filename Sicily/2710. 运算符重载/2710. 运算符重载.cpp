class numCal {
  public:
    numCal(int a[], int s) {
        size = s;
        if (size == 0) {
            arr = NULL;
        } else {
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = a[i];
            }
        }
    }

    numCal(const numCal& k) {
        size = k.getSize();
        if (size == 0) {
            arr = NULL;
        } else {
            int* v = k.getArr();
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = v[i];
            }
        }
    }

    ~numCal() {
        if (arr) {
            delete []arr;
            arr = NULL;
        }
    }

    int sum() {
        int res = 0;
        for (int i = 0; i < size; i++) {
            res += arr[i];
        }
        return res;
    }

    numCal& operator=(const numCal& k) {
        size = k.getSize();
        if (arr != NULL) {
            delete []arr;
        }
        if (size == 0) {
            arr = NULL;
        } else {
            arr = new int[size];
            int* v = k.getArr();
            for (int i = 0; i < size; i++) {
                arr[i] = v[i];
            }
        }
        return *this;
    }

    numCal& operator++() {
        for (int i = 0; i < size; i++) {
            arr[i] += 1;
        }
        return *this;
    }

    numCal operator++(int) {
        numCal e(*this);
        ++(*this);
        return e;
    }

    int getSize(void) const{
        return size;
    }

    int* getArr(void) const {
        return arr;
    }

private:
    int size;
    int *arr;
};
