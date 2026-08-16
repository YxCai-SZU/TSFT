#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 13;

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_range: \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        3 <= total_sum(a, b, c) <= 39;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a + b + c >= 22);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool is_already_21;
    bool result;

    sum = a + b + c;
    is_already_21 = false;

    //@ assert sum == total_sum(a, b, c);

    if (sum == 21)
    {
        is_already_21 = true;
    }

    if (is_already_21)
    {
        sum = sum;
    }
    else
    {
        sum = sum + 1;
    }

    //@ assert sum == total_sum(a, b, c) + 1 || sum == 21;

    if (sum >= 22)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (a + b + c >= 22);
    return result;
}
