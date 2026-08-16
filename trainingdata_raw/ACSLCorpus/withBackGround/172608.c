#include <stdbool.h>

/*@
    predicate is_divisible_and_within_bounds(integer a, integer b, integer x) =
        x % a == 0 && (x / a) <= b;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 100;
    ensures \result <==> is_divisible_and_within_bounds(a, b, x);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    bool result;
    //@ ghost unsigned long long tmp_mod = x % a;
    //@ ghost unsigned long long tmp_div = x / a;

    //@ assert tmp_mod == x % a;
    //@ assert tmp_div == x / a;
    //@ assert (tmp_mod == 0 && tmp_div <= b) <==> is_divisible_and_within_bounds(a, b, x);

    result = (x % a == 0) && ((x / a) <= b);
    return result;
}
