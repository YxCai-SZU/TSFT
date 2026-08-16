#include <stddef.h>

/*@
    predicate is_multiple_of_1000(integer n) = n % 1000 == 0;
    predicate not_multiple_of_1000(integer n) = n % 1000 != 0;
    logic integer remainder(integer n) = n % 1000;
    logic integer complement(integer n) = 1000 - remainder(n);
*/

/*@
    requires 1 <= n <= 10000;
    ensures is_multiple_of_1000(n) ==> \result == 0;
    ensures not_multiple_of_1000(n) ==> \result == complement(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t r;
    size_t ans;

    r = n % 1000;
    //@ assert r == remainder(n);

    if (r == 0) {
        ans = 0;
        //@ assert is_multiple_of_1000(n);
        //@ assert ans == 0;
    } else {
        ans = 1000 - r;
        //@ assert not_multiple_of_1000(n);
        //@ assert ans == complement(n);
    }

    return ans;
}
