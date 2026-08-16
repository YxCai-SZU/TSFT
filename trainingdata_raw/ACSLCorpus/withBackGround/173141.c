#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (a + b + 1) / 2;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t sum;
    size_t average;

    //@ assert valid_range(a) && valid_range(b);
    sum = a + b;
    //@ assert sum == a + b;
    average = (sum + 1) / 2;
    //@ assert average == (a + b + 1) / 2;
    return average;
}
