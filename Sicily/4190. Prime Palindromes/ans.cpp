// Problem#: 4190
// Submission#: 3434563
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<stdio.h>
#include<string>
#include<memory.h>
#include <math.h>
using namespace std;

#define MAX 10000000//比题目要求少一个0即可，加多一个0则内存溢出老是RE！
bool prime[MAX+1]; //prime[i]=true表示i为素数
int PrimePalindromeList[100000]={0};

void createPrimeList();
bool isPalindrome(int n);
void createPrimePalindromeList();

int main() {
  createPrimeList();
  createPrimePalindromeList();
  int a,b;
  while(scanf("%d %d", &a, &b), a != 0 && b != 0){
    int i=0;
    while(PrimePalindromeList[i]<=b&&PrimePalindromeList[i]!=0){
      if (PrimePalindromeList[i] >= a)
        printf("%d\n",PrimePalindromeList[i]);
      i++;
    }
  }
  return 0;
}

void createPrimeList(){
  memset(prime, true, sizeof(prime));
  for (int i = 2; i * i < MAX; ++i) {
    int temp = 2 * i;
    if (prime[i]) {
      while (temp <= MAX) {
        prime[temp] = false;
        temp += i;
      }
    }
  }
}
bool isPalindrome(int a){
  int b = a, temp = 0;
  do {
    temp = temp * 10 + b % 10;
    b /= 10;
  } while (b);

  if (a == temp) return true;
  return false;
}
void createPrimePalindromeList(){
   int count = 0;
  for (int i = 5; i <= MAX; ++i) {
    if (prime[i] && isPalindrome(i)) {
      PrimePalindromeList[count] = i;
      ++count;
    }
  }
}                                 
