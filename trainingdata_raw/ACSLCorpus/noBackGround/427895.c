#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == ((a) * (c)) || \result == ((b) * (c)) || 
            \result == ((a) * (d)) || \result == ((b) * (d));
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max1;
    long long max2;
    long long result;
    
    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    
    //@ assert ((a) * (c)) <= 1000000000000000000;
    //@ assert ((b) * (c)) <= 1000000000000000000;
    //@ assert ((a) * (d)) <= 1000000000000000000;
    //@ assert ((b) * (d)) <= 1000000000000000000;
    
    if (a * c > b * c) {
        max1 = a * c;
    } else {
        max1 = b * c;
    }
    
    if (a * d > b * d) {
        max2 = a * d;
    } else {
        max2 = b * d;
    }
    
    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }
    
    //@ assert result == ((a) * (c)) || result == ((b) * (c)) || result == ((a) * (d)) || result == ((b) * (d));
    return result;
}
