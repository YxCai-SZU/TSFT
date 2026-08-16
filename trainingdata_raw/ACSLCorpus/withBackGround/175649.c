#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 13;

    logic integer sum_three(integer a, integer b, integer c) = a + b + c;

    lemma sum_range:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            3 <= sum_three(a, b, c) <= 39;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long sum;
    bool is_bust;

    sum = a + b + c;
    is_bust = false;

    //@ assert 3 <= sum_three(a, b, c) <= 39;
    //@ assert sum == sum_three(a, b, c);

    if (sum >= 22)
    {
        is_bust = true;
    }

    //@ assert is_bust == (sum_three(a, b, c) >= 22);
    return is_bust;
}
