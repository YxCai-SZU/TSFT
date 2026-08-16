#include <stdbool.h>

/*@
    requires 0 <= a && a <= 123;
    requires 0 <= b && b <= 123;
    requires 0 <= c && c <= 123;
    requires 0 <= d && d <= 123;
    requires 0 <= e && e <= 123;
    requires 0 <= k && k <= 123;
    requires a < b && b < c && c < d && d < e;
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long count = 0;
    long current = a;
    
    //@ assert a <= current && current <= e;
    //@ assert count >= 0;
    //@ assert count <= current - a;
    //@ assert count == current - a;
    
    /*@
        loop invariant a <= current && current <= e;
        loop invariant count >= 0;
        loop invariant count <= current - a;
        loop invariant count == current - a;
        loop assigns count, current;
    */
    while (current < e) {
        count += 1;
        current += 1;
        //@ assert count == current - a;
    }
    
    //@ assert count == e - a;
    return count <= k;
}
