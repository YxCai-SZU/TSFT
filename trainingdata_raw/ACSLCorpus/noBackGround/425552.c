#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> ((a) < (b) && (b) < (c) && (c) < (d));
 */
bool func(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d)) <==> a < b && b < c && c < d;
    
    if (a >= b || b >= c || c >= d) {
        return false;
    } else {
        return true;
    }
}
