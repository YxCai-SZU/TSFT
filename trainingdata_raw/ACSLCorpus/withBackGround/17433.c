#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_of_three(integer a, integer b, integer c) = a + b + c;

    lemma sum_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            1 <= sum_of_three(a, b, c) <= 300;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a + b + c) / 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int sum;
    int quotient;
    int remainder;
    int three;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    //@ assert 1 <= a + b + c <= 300;

    sum = a + b + c;
    quotient = 0;
    remainder = sum;
    three = 3;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= sum / 3;
        loop invariant remainder == sum - quotient * three;
        loop invariant 0 <= remainder < three + sum;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= three)
    {
        //@ assert remainder >= three;
        quotient = quotient + 1;
        remainder = remainder - three;
        //@ assert remainder == sum - quotient * three;
    }

    //@ assert quotient == (a + b + c) / 3;
    return quotient;
}
