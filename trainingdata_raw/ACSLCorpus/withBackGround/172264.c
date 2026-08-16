#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        -10000 <= a <= 10000 &&
        -10000 <= b <= 10000 &&
        -10000 <= c <= 10000 &&
        -10000 <= d <= 10000 &&
        a <= b &&
        c <= d;

    logic integer product1(integer a, integer b, integer c, integer d) = a * c;
    logic integer product2(integer a, integer b, integer c, integer d) = a * d;
    logic integer product3(integer a, integer b, integer c, integer d) = b * c;
    logic integer product4(integer a, integer b, integer c, integer d) = b * d;

    lemma product_bounds1:
        \forall integer a, c; -10000 <= a <= 10000 && -10000 <= c <= 10000 ==>
        -100000000 <= a * c <= 100000000;

    lemma product_bounds2:
        \forall integer a, d; -10000 <= a <= 10000 && -10000 <= d <= 10000 ==>
        -100000000 <= a * d <= 100000000;

    lemma product_bounds3:
        \forall integer b, c; -10000 <= b <= 10000 && -10000 <= c <= 10000 ==>
        -100000000 <= b * c <= 100000000;

    lemma product_bounds4:
        \forall integer b, d; -10000 <= b <= 10000 && -10000 <= d <= 10000 ==>
        -100000000 <= b * d <= 100000000;
*/

/*@
    requires bounds(a, b, c, d);
    ensures \result == product4(a, b, c, d) ||
            \result == product3(a, b, c, d) ||
            \result == product2(a, b, c, d) ||
            \result == product1(a, b, c, d);
*/
long func(long a, long b, long c, long d)
{
    long tmp[4];
    long max_value;
    int i;

    //@ assert -10000 <= a && a <= 10000;
    //@ assert -10000 <= c && c <= 10000;
    //@ assert -100000000 <= a * c && a * c <= 100000000;
    tmp[0] = a * c;

    //@ assert -10000 <= a && a <= 10000;
    //@ assert -10000 <= d && d <= 10000;
    //@ assert -100000000 <= a * d && a * d <= 100000000;
    tmp[1] = a * d;

    //@ assert -10000 <= b && b <= 10000;
    //@ assert -10000 <= c && c <= 10000;
    //@ assert -100000000 <= b * c && b * c <= 100000000;
    tmp[2] = b * c;

    //@ assert -10000 <= b && b <= 10000;
    //@ assert -10000 <= d && d <= 10000;
    //@ assert -100000000 <= b * d && b * d <= 100000000;
    tmp[3] = b * d;

    max_value = tmp[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == tmp[k];
        loop invariant bounds(a, b, c, d);
        loop invariant \forall integer j; 0 <= j < 4 ==> tmp[j] == tmp[j];
        loop assigns i, max_value;
    */
    while (i < 4)
    {
        if (tmp[i] > max_value)
        {
            max_value = tmp[i];
        }
        i++;
    }

    return max_value;
}
