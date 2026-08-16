#include <stdbool.h>

/*@
    predicate remainder_correct(integer n, integer r) =
        r == n / 15;

    predicate total_correct(integer n, integer r, integer t) =
        t == n * 800 - r * 200;

    logic integer compute_remainder(integer n) = n / 15;

    logic integer compute_total(integer n, integer r) = n * 800 - r * 200;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == (n * 800 - (n / 15) * 200 >= 200);
*/
bool func(unsigned long n)
{
    unsigned long remainder;
    unsigned long total_200s;
    bool result;

    remainder = n / 15;
    //@ assert remainder_correct(n, remainder);

    total_200s = n * 800 - remainder * 200;
    //@ assert total_correct(n, remainder, total_200s);

    result = total_200s >= 200;
    return result;
}
