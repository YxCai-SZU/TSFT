#include <stdint.h>

/*@
    predicate in_range(integer a) = -100 <= a <= 100;

    logic integer sum_val(integer a, integer b) = a + b;
    logic integer diff_val(integer a, integer b) = a - b;
    logic integer prod_val(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> -10000 <= prod_val(a, b) <= 10000;

    lemma max_property:
        \forall integer a, b, max_val;
            (max_val == sum_val(a, b) || max_val == diff_val(a, b) || max_val == prod_val(a, b)) &&
            max_val >= sum_val(a, b) &&
            max_val >= diff_val(a, b) &&
            max_val >= prod_val(a, b) &&
            in_range(a) && in_range(b) ==>
            max_val >= prod_val(a, b);
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t sum;
    int64_t diff;
    int64_t prod;
    int64_t max_val;

    sum = a + b;
    diff = a - b;

    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;

    if (sum > diff)
    {
        if (sum > prod)
        {
            max_val = sum;
        }
        else
        {
            max_val = prod;
        }
    }
    else
    {
        if (diff > prod)
        {
            max_val = diff;
        }
        else
        {
            max_val = prod;
        }
    }

    //@ assert max_val >= a * b;
    return max_val;
}
