#include <stdint.h>

/*@
    predicate valid_range(integer x) = 3 <= x && x <= 20;

    logic integer max_of_three(integer a, integer b) =
        (a + b > 2 * a - 1) ? (a + b) : (2 * a - 1);

    logic integer final_max(integer a, integer b) =
        (max_of_three(a, b) > 2 * b - 1) ? max_of_three(a, b) : (2 * b - 1);

    lemma max_property:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            (final_max(a, b) == a + b ||
             final_max(a, b) == 2 * a - 1 ||
             final_max(a, b) == 2 * b - 1);

    lemma non_negative:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> final_max(a, b) >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t max_value;
    int64_t temp;

    // First comparison
    if (a + b > 2 * a - 1)
    {
        max_value = a + b;
    }
    else
    {
        max_value = 2 * a - 1;
    }

    // Second comparison
    if (max_value > 2 * b - 1)
    {
        temp = max_value;
    }
    else
    {
        temp = 2 * b - 1;
    }

    //@ assert temp == a + b || temp == 2 * a - 1 || temp == 2 * b - 1;
    return temp;
}
