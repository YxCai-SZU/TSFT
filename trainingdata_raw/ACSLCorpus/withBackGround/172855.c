#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer expr1(integer a, integer b, integer c) = a * 10 + b + c;
    logic integer expr2(integer a, integer b, integer c) = a + b * 10 + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c * 10;

    lemma max_satisfies_one:
        \forall integer a, b, c, max_val;
        valid_input(a, b, c) &&
        (max_val == expr1(a, b, c) || max_val == expr2(a, b, c) || max_val == expr3(a, b, c))
        ==>
        (max_val >= expr1(a, b, c) || max_val >= expr2(a, b, c) || max_val >= expr3(a, b, c));
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 10 && \result <= 999;
    ensures \result >= expr1(a, b, c) || \result >= expr2(a, b, c) || \result >= expr3(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max_val;
    int temp_val;

    max_val = a * 10 + b + c;
    temp_val = a + b * 10 + c;

    //@ assert max_val >= expr1(a, b, c) || max_val >= expr2(a, b, c) || max_val >= expr3(a, b, c);
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    //@ assert max_val >= expr1(a, b, c) || max_val >= expr2(a, b, c) || max_val >= expr3(a, b, c);
    temp_val = a + b + c * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    //@ assert max_val == expr1(a, b, c) || max_val == expr2(a, b, c) || max_val == expr3(a, b, c);
    //@ assert max_val >= expr1(a, b, c) || max_val >= expr2(a, b, c) || max_val >= expr3(a, b, c);
    return max_val;
}
