#include <stdbool.h>

/*@
    requires 1 <= n <= 1000;
    requires 1 <= m <= 1000;
    requires 0 <= k <= n * m;
    ensures \result == (k <= (n - 1) * m + (m - 1) * 1);
*/
bool func(long n, long m, long k)
{
    long max_val;
    long min_val;
    long s;
    bool result;
    
    // Calculate max manually
    //@ assert 1 <= n <= 1000 && 1 <= m <= 1000;
    if (n > m) {
        max_val = n;
        //@ assert (((n) > (m) ==> (max_val) == (n)) && ((n) <= (m) ==> (max_val) == (m)));
    } else {
        max_val = m;
        //@ assert (((n) > (m) ==> (max_val) == (n)) && ((n) <= (m) ==> (max_val) == (m)));
    }
    
    // Calculate min manually
    //@ assert 1 <= n <= 1000 && 1 <= m <= 1000;
    if (n < m) {
        min_val = n;
        //@ assert (((n) < (m) ==> (min_val) == (n)) && ((n) >= (m) ==> (min_val) == (m)));
    } else {
        min_val = m;
        //@ assert (((n) < (m) ==> (min_val) == (n)) && ((n) >= (m) ==> (min_val) == (m)));
    }
    
    // Ensure no overflow in multiplication
    //@ assert 0 <= max_val * min_val <= 1000000;
    
    // Calculate s
    s = max_val * min_val - 1;
    //@ assert s == max_val * min_val - 1;
    
    // Verify s equals the target expression
    //@ assert s == (n - 1) * m + (m - 1) * 1;
    
    result = (k <= s);
    //@ assert result == (k <= (n - 1) * m + (m - 1) * 1);
    return result;
}
