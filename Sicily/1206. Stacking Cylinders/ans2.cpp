#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int main () {
    int n ;
    double a[108] ;
    double x , y ;
    while ( scanf( "%d" , &n )  && n ) {
        x = 0 ;
        y = 1 ;
        for ( int i = 0 ; i < n ; ++i ) {
            scanf( "%lf" , &a[i] ) ;
        //  x += a[i] ;
        }
        sort ( a , a+n ) ;
        x = (a[0]+a[n-1])/2 ;
        for ( int i = 0 ; i < n-1 ; ++i ) {
            y += sqrt( 4 - pow ((a[i+1]-a[i])/2,2) ) ;
        }
        printf ( "%.4lf %.4lf\n" , x , y ) ;
    }
    return 0 ;
}