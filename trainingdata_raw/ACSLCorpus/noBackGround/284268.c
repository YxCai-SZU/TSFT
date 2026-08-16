#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000000000 &&
        1 <= (k) && (k) <= 100000000000 &&
        1 <= (a) && (a) <= 100000000000);
    ensures \result == (k - a + 1 >= n);
    assigns \nothing;
*/
bool func(long n, long k, long a)
{
    long min_val;
    //@ assert 1 <= n && n <= 100000000000;
    //@ assert 1 <= k && k <= 100000000000;
    //@ assert 1 <= a && a <= 100000000000;
    
    if (k - a + 1 < n) {
        min_val = k - a + 1;
    } else {
        min_val = n;
    }
    
    return n <= k - a + 1;
}
