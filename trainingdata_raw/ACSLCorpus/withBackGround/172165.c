#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    predicate is_monotonic(integer a, integer b, integer c) =
        (a < b && b < c) || (a > b && b > c);
*/

/*@
    requires \valid_read(v + (0..2));
    requires is_valid_range(v[0]);
    requires is_valid_range(v[1]);
    requires is_valid_range(v[2]);
    assigns \nothing;
    ensures \result == true <==> is_monotonic(v[0], v[1], v[2]);
*/
bool func(const unsigned int v[3])
{
    bool result;

    //@ assert is_valid_range(v[0]);
    //@ assert is_valid_range(v[1]);
    //@ assert is_valid_range(v[2]);

    result = (v[0] < v[1] && v[1] < v[2]) || (v[0] > v[1] && v[1] > v[2]);
    return result;
}
