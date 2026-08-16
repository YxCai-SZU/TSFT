#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    lemma expr1_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            12 <= expr1(a, b, c) <= 108;

    lemma expr2_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            12 <= expr2(a, b, c) <= 108;

    lemma expr3_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            12 <= expr3(a, b, c) <= 108;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    requires INT_MIN <= a * 10 + b + c <= INT_MAX;
    requires INT_MIN <= a + b * 10 + c <= INT_MAX;
    requires INT_MIN <= a + b + c * 10 <= INT_MAX;
    ensures \result == expr1(a, b, c) ||
            \result == expr2(a, b, c) ||
            \result == expr3(a, b, c);
    ensures \result >= 11;
*/
int func(int a, int b, int c)
{
    int max1;
    int result;

    //@ assert 12 <= a * 10 + b + c <= 108;
    //@ assert 12 <= a + b * 10 + c <= 108;
    //@ assert 12 <= a + b + c * 10 <= 108;

    if (a * 10 + b + c > a + b * 10 + c)
    {
        max1 = a * 10 + b + c;
    }
    else
    {
        max1 = a + b * 10 + c;
    }

    if (max1 > a + b + c * 10)
    {
        result = max1;
    }
    else
    {
        result = a + b + c * 10;
    }

    //@ assert result >= 11;
    return result;
}
