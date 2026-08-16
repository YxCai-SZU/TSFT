#include <stdint.h>

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == (((a) <= (b)) ? (a) : (b)) + (((c) <= (d)) ? (c) : (d));
    ensures \result <= 20000;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ans;
    int64_t min_ab;
    int64_t min_cd;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;
    
    // Calculate min(a,b)
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    
    //@ assert (((a) <= (b) ==> (min_ab) == (a)) && ((a) > (b) ==> (min_ab) == (b)));
    //@ assert min_ab == (((a) <= (b)) ? (a) : (b));
    //@ assert 1 <= min_ab <= 10000;
    
    // Calculate min(c,d)
    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    
    //@ assert (((c) <= (d) ==> (min_cd) == (c)) && ((c) > (d) ==> (min_cd) == (d)));
    //@ assert min_cd == (((c) <= (d)) ? (c) : (d));
    //@ assert 1 <= min_cd <= 10000;
    
    //@ assert min_ab + min_cd <= 20000;
    
    ans = min_ab + min_cd;
    
    //@ assert ans == (((a) <= (b)) ? (a) : (b)) + (((c) <= (d)) ? (c) : (d));
    return ans;
}
