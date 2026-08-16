#include <stdbool.h>
#include <limits.h>

/*@
    predicate is_valid_i64(integer x) =
        x != LLONG_MIN && x <= LLONG_MAX;
*/

/*@
    requires is_valid_i64(a) && is_valid_i64(b) && is_valid_i64(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    // Variable declarations at top of scope
    bool result;

    // Precondition assertions
    //@ assert a <= LLONG_MAX;
    //@ assert b <= LLONG_MAX;
    //@ assert c <= LLONG_MAX;
    //@ assert a != LLONG_MIN;
    //@ assert b != LLONG_MIN;
    //@ assert c != LLONG_MIN;

    result = (a < b) && (b < c);
    return result;
}
