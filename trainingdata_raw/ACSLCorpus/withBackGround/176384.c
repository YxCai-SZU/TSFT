#include <stdbool.h>

/*@
    predicate is_small(integer n, integer m) = n < 15 || m < 15;
    predicate is_large(integer n, integer m) = n >= 15 && m >= 15;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures is_small(n, m) ==> \result == 0;
    ensures is_large(n, m) ==> \result == 1;
*/
int func(int n, int m)
{
    int result;
    //@ ghost int old_n = n;
    //@ ghost int old_m = m;

    if (n < 15 || m < 15)
    {
        //@ assert is_small(old_n, old_m);
        result = 0;
        return result;
    }

    //@ assert is_large(old_n, old_m);
    result = 1;
    return result;
}
