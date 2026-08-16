#include <limits.h>

/*@
    predicate is_valid_int(integer x) =
        x > INT_MIN && x < INT_MAX;

    logic integer min_of_three(integer a, integer b, integer c) =
        (a <= b && a <= c) ? a :
        (b <= a && b <= c) ? b : c;

    lemma min_is_first_or_second_or_third:
        \forall integer a, b, c;
            is_valid_int(a) && is_valid_int(b) && is_valid_int(c) ==>
            (min_of_three(a, b, c) == a || min_of_three(a, b, c) == b || min_of_three(a, b, c) == c);

    lemma min_is_less_or_equal_first:
        \forall integer a, b, c;
            is_valid_int(a) && is_valid_int(b) && is_valid_int(c) ==>
            min_of_three(a, b, c) <= a;

    lemma min_is_less_or_equal_second:
        \forall integer a, b, c;
            is_valid_int(a) && is_valid_int(b) && is_valid_int(c) ==>
            min_of_three(a, b, c) <= b;

    lemma min_is_less_or_equal_third:
        \forall integer a, b, c;
            is_valid_int(a) && is_valid_int(b) && is_valid_int(c) ==>
            min_of_three(a, b, c) <= c;
*/

/*@
    requires is_valid_int(a) && is_valid_int(b) && is_valid_int(c);
    ensures \result == a || \result == b || \result == c;
    ensures \result <= a && \result <= b && \result <= c;
    assigns \nothing;
*/
int min_numbers(int a, int b, int c)
{
    int ret;

    //@ assert a > INT_MIN && a < INT_MAX;
    //@ assert b > INT_MIN && b < INT_MAX;
    //@ assert c > INT_MIN && c < INT_MAX;

    if (a <= b && a <= c)
    {
        //@ assert a <= b && a <= c;
        ret = a;
    }
    else if (b <= a && b <= c)
    {
        //@ assert b <= a && b <= c;
        ret = b;
    }
    else
    {
        //@ assert c <= a && c <= b;
        ret = c;
    }

    //@ assert ret == a || ret == b || ret == c;
    //@ assert ret <= a && ret <= b && ret <= c;

    return ret;
}
