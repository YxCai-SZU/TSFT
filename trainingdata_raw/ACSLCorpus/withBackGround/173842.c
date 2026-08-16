#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer d) =
        a >= 1 && b >= 1 && c >= 1 && d >= 1 &&
        a <= 20 && b <= 20 && c <= 20 && d <= 20;

    logic integer min_of_two(integer x, integer y) = (x < y) ? x : y;

    logic integer total_sum(integer a, integer b, integer c, integer d) = a + b + c + d;

    lemma res_bounds:
        \forall integer a, b, c, d, min1, min2, min, res;
        valid_input(a, b, c, d) ==>
        min1 == min_of_two(a, b) ==>
        min2 == min_of_two(c, d) ==>
        min == min_of_two(min1, min2) ==>
        res == min + (a - min) + (b - min) + (c - min) + (d - min) ==>
        res >= 0 && res <= total_sum(a, b, c, d);
*/

/*@
    requires valid_input(a, b, c, d);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min1;
    int min2;
    int min;
    int res;

    //@ assert a >= 1 && b >= 1 && c >= 1 && d >= 1;
    //@ assert a <= 20 && b <= 20 && c <= 20 && d <= 20;

    if (a < b)
    {
        min1 = a;
    }
    else
    {
        min1 = b;
    }
    //@ assert min1 == min_of_two(a, b);

    if (c < d)
    {
        min2 = c;
    }
    else
    {
        min2 = d;
    }
    //@ assert min2 == min_of_two(c, d);

    if (min1 < min2)
    {
        min = min1;
    }
    else
    {
        min = min2;
    }
    //@ assert min == min_of_two(min1, min2);

    res = min + (a - min) + (b - min) + (c - min) + (d - min);
    //@ assert res >= 0;
    //@ assert res <= a + b + c + d;

    return res;
}
