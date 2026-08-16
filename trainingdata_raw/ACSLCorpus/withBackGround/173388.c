#include <limits.h>

/*@
    predicate valid_input(integer x) = 1 <= x <= 100;

    logic integer half_plus_remainder(integer x) = x / 2 + (x % 2);

    lemma half_remainder_formula:
        \forall integer x; valid_input(x) ==> half_plus_remainder(x) == x / 2 + (x % 2);
*/

/*@
    requires valid_input(x);
    ensures \result == half_plus_remainder(x);
    ensures \result == x / 2 + (x % 2);
*/
int func(int x)
{
    int half;
    int count;
    int remainder;
    int result;

    half = 0;
    count = x;

    /*@
        loop invariant 0 <= half <= x / 2;
        loop invariant 0 <= count <= x;
        loop invariant count == x - 2 * half;
        loop assigns half, count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        half = half + 1;
        count = count - 2;
    }

    if (count == 1)
    {
        remainder = 1;
    }
    else
    {
        remainder = 0;
    }

    result = half + remainder;
    //@ assert result == half_plus_remainder(x);
    return result;
}
