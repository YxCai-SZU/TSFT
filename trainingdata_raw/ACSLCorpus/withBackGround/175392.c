#include <limits.h>

/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_valid_range(integer x) = 1 <= x <= 20;
*/

/*@
    requires is_valid_range(n) && is_valid_range(m);
    ensures (is_small(n) && is_small(m)) ==> \result == n * m;
    ensures (!is_small(n) || !is_small(m)) ==> \result == -1;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result = 0;

    //@ assert is_valid_range(n) && is_valid_range(m);
    
    if (1 <= n && n <= 9 && 1 <= m && m <= 9) {
        //@ assert is_small(n) && is_small(m);
        //@ assert n * m <= 81;
        result = n * m;
    } else {
        result = -1;
    }
    
    return result;
}
