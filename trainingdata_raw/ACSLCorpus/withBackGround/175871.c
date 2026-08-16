#include <stdbool.h>

/*@
    predicate is_in_range(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
*/

/*@
    requires is_in_range(n, m);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    int max_val;
    int min_val;
    int abs_val;
    bool result;

    //@ assert is_in_range(n, m);
    
    // Implementing max function manually
    if (n > m) {
        max_val = n;
    } else {
        max_val = m;
    }
    
    // Implementing min function manually
    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }
    
    // Implementing abs function manually
    if (n - m < 0) {
        abs_val = m - n;
    } else {
        abs_val = n - m;
    }
    
    //@ assert n == m ==> n == m;
    
    result = (n == m);
    //@ assert result == (n == m);
    return result;
}
