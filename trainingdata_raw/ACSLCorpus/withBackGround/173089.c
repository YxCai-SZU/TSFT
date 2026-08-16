#include <stdbool.h>

/*@ predicate is_arithmetic_sequence(integer a, integer b, integer c) =
      b - a == c - b;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    int diff_b_a;
    int diff_c_b;
    bool result;

    diff_b_a = b - a;
    diff_c_b = c - b;

    //@ assert diff_b_a == b - a;
    //@ assert diff_c_b == c - b;

    result = (diff_b_a == diff_c_b);
    return result;
}
