#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d) =
        -1000 <= a <= 1000 &&
        -1000 <= b <= 1000 &&
        -1000 <= c <= 1000 &&
        -1000 <= d <= 1000 &&
        a <= b &&
        c <= d;

    logic integer product_bound(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer a, b, c, d;
            is_valid_range(a, b, c, d) ==>
            -1000000 <= product_bound(a, c) <= 1000000 &&
            -1000000 <= product_bound(a, d) <= 1000000 &&
            -1000000 <= product_bound(b, c) <= 1000000 &&
            -1000000 <= product_bound(b, d) <= 1000000;
*/

/*@
    requires is_valid_range(a, b, c, d);
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int tmp[4];
    int max_val;
    int i;

    //@ assert a >= -1000 && a <= 1000;
    //@ assert c >= -1000 && c <= 1000;
    //@ assert a * c >= -1000000 && a * c <= 1000000;
    tmp[0] = a * c;

    //@ assert a >= -1000 && a <= 1000;
    //@ assert d >= -1000 && d <= 1000;
    //@ assert a * d >= -1000000 && a * d <= 1000000;
    tmp[1] = a * d;

    //@ assert b >= -1000 && b <= 1000;
    //@ assert c >= -1000 && c <= 1000;
    //@ assert b * c >= -1000000 && b * c <= 1000000;
    tmp[2] = b * c;

    //@ assert b >= -1000 && b <= 1000;
    //@ assert d >= -1000 && d <= 1000;
    //@ assert b * d >= -1000000 && b * d <= 1000000;
    tmp[3] = b * d;

    max_val = tmp[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= tmp[j];
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (tmp[i] > max_val)
        {
            max_val = tmp[i];
        }
        i = i + 1;
    }

    return max_val;
}
