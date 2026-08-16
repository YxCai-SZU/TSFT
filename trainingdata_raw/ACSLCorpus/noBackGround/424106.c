#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long s1;
    long s2;
    long ans;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert product_bounds: 1 <= ((a) * (b)) <= 10000 * 10000;
    //@ assert product_bounds: 1 <= ((c) * (d)) <= 10000 * 10000;
    
    s1 = a * b;
    s2 = c * d;
    
    if (s1 > s2) {
        ans = s1;
        //@ assert ans == ((a) * (b));
    } else {
        ans = s2;
        //@ assert ans == ((c) * (d));
    }
    
    //@ assert ans >= ((a) * (b));
    //@ assert ans >= ((c) * (d));
    
    return ans;
}
