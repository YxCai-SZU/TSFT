#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= (b) <= 1000000000);
    requires (-1000000000 <= (c) <= (d) <= 1000000000);
    requires a <= INT_MAX && a >= INT_MIN;
    requires b <= INT_MAX && b >= INT_MIN;
    requires c <= INT_MAX && c >= INT_MIN;
    requires d <= INT_MAX && d >= INT_MIN;
    ensures \result == a * c || \result == b * c || \result == a * d || \result == b * d;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long x;
    
    //@ assert -1000000000 <= a && a <= 1000000000;
    //@ assert -1000000000 <= c && c <= 1000000000;
    
    //@ assert -1000000000000000000 <= a * c && a * c <= 1000000000000000000;
    x = a * c;
    
    //@ assert -1000000000000000000 <= b * c && b * c <= 1000000000000000000;
    if (b * c > x) {
        x = b * c;
    }
    
    //@ assert -1000000000000000000 <= a * d && a * d <= 1000000000000000000;
    if (a * d > x) {
        x = a * d;
    }
    
    //@ assert -1000000000000000000 <= b * d && b * d <= 1000000000000000000;
    if (b * d > x) {
        x = b * d;
    }
    
    //@ assert x == a * c || x == b * c || x == a * d || x == b * d;
    return x;
}
