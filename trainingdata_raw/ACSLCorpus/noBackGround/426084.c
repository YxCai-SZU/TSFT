#include <stdbool.h>

/*@ requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long ans;
    //@ assert (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    
    if (a > e) {
        ans = a - e;
    } else {
        ans = e - a;
    }
    
    //@ assert ans == ((a) > (e) ? (a) - (e) : (e) - (a));
    //@ assert ans == e - a || ans == a - e;
    
    return ans <= k;
}
