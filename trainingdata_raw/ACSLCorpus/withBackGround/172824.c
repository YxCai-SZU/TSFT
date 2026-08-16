#include <stdbool.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

/*@ predicate vector_valid(int *v, integer len) =
    len == 2 &&
    \forall integer i; 0 <= i < len ==> valid_range(v[i]); */

/*@ lemma subtraction_bounds:
    \forall integer a, b; valid_range(a) && valid_range(b) ==> a - b >= -99; */

/*@ requires \valid(v + (0 .. 1));
    requires vector_valid(v, 2);
    ensures \result == (v[0] <= v[1]);
    assigns \nothing;
 */
bool func(int *v)
{
    //@ assert valid_range(v[0]);
    //@ assert valid_range(v[1]);
    //@ assert v[0] - v[1] >= -99;
    return v[0] <= v[1];
}
