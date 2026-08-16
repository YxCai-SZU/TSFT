#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) <= 123 && (b) <= 123 && (c) <= 123 && (d) <= 123 && (e) <= 123 &&
        (k) >= 0 && (k) <= 123 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
 */
bool func(long a, long b, long c, long d, long e, long k)
{
    long r = 0;
    bool result;
    //@ assert e - a >= 0;
    
    if (e - a > k) {
        long n = e - a - k;
        long res = 0;
        //@ assert n >= 0;
        //@ assert ((n) + 5 * (res)) == e - a - k;
        
        /*@
            loop invariant n >= 0;
            loop invariant res >= 0;
            loop invariant ((n) + 5 * (res)) == e - a - k;
            loop assigns n, res;
         */
        while (n >= 5) {
            //@ assert n >= 5;
            n -= 5;
            //@ assert n >= 0;
            res += 1;
            //@ assert ((n) + 5 * (res)) == e - a - k;
        }
        //@ assert n < 5;
        //@ assert ((n) + 5 * (res)) == e - a - k;
        r = res;
    }
    
    result = (e - a <= k);
    //@ assert result == (e - a <= k);
    return result;
}
