#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_val(integer a, integer b) = a + b;
    logic integer avg_val(integer s) = s / 2;
    predicate is_odd_sum(integer s) = s % 2 != 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (sum_val(a, b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    unsigned int avg;
    bool is_odd;

    //@ assert valid_range(a);
    //@ assert valid_range(b);

    sum = a + b;
    //@ assert sum == sum_val(a, b);

    avg = sum / 2;
    //@ assert avg == avg_val(sum);

    is_odd = (sum % 2) != 0;
    //@ assert is_odd == (sum_val(a, b) % 2 != 0);

    return is_odd;
}
