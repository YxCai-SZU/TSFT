#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        0 <= m && m <= n;

    logic integer subtract(integer n, integer m) = n - m;
*/

/*@
    requires is_valid_params(n, m);
    ensures \result == subtract(n, m);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int result = 0;
    bool is_negative = false;
    unsigned int temp_n = n;
    unsigned int temp_m = m;

    if (temp_n < temp_m) {
        is_negative = true;
    } else {
        result = temp_n - temp_m;
    }

    if (is_negative) {
        //@ assert n >= m;
        //@ assert 0 <= subtract(n, m) && subtract(n, m) <= 100;
        result = 0;
    }

    //@ assert is_negative ==> result == 0;
    //@ assert !is_negative ==> result == subtract(n, m);

    return result;
}
