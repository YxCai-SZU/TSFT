/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a <= 500 &&
        1 <= b <= 500 &&
        1 <= c <= 1000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_positive: \forall integer a, b; 1 <= a <= 500 && 1 <= b <= 500 ==> sum(a, b) >= 2;
*/

#include <stdbool.h>

/*@
    requires valid_range(a, b, c);
    ensures \result == (sum(a, b) >= c);
*/
bool func(int a, int b, int c)
{
    int n;
    int i;

    n = 0;
    i = 1;

    /*@
        loop invariant 1 <= a <= 500;
        loop invariant 1 <= b <= 500;
        loop invariant 1 <= c <= 1000;
        loop invariant 0 <= n;
        loop invariant i >= 1;
        loop invariant i <= b + 1;
        loop invariant n == (i - 1) * 1;
        loop assigns n, i;
    */
    while (i <= b)
    {
        //@ assert i <= b;
        n += 1;
        i += 1;
    }

    int sum_val;
    if (a > -b)
    {
        sum_val = a - (-b);
    }
    else
    {
        sum_val = -(-b - a);
    }

    //@ assert sum_val == sum(a, b);

    return sum_val >= c;
}
