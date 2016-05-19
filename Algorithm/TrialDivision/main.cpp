#include "iostream"

bool isPrime(int n) {
    if (n < 2) return false;
    
    if (n % 2 == 0) return false;

    for (int i = 3; i * i < n; i += 2) {
	if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    
    return 0;
}

