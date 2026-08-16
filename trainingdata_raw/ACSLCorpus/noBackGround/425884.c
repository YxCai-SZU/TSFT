#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == a * d || \result == b * c || \result == a * c;
*/
long func(long a, long b, long c, long d) {
    long max1;
    long max2;
    long res;
    
    //@ assert a >= -1000000000 && a <= 1000000000;
    //@ assert c >= -1000000000 && c <= 1000000000;
    
    //@ assert a * c >= -1000000000000000000 && a * c <= 1000000000000000000;
    //@ assert a * d >= -1000000000000000000 && a * d <= 1000000000000000000;
    
    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }
    
    //@ assert b * c >= -1000000000000000000 && b * c <= 1000000000000000000;
    //@ assert b * d >= -1000000000000000000 && b * d <= 1000000000000000000;
    
    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }
    
    //@ assert max1 == a * c || max1 == a * d;
    //@ assert max2 == b * c || max2 == b * d;
    
    if (max1 > max2) {
        res = max1;
    } else {
        res = max2;
    }
    
    return res;
}
