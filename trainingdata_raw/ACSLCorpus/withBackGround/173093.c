#include <stdbool.h>

/*@
    predicate in_range(integer v) = -10000 <= v <= 10000;
    predicate product_in_range(integer v) = -100000000 <= v <= 100000000;
    predicate is_product(integer v, integer a, integer b, integer c, integer d) =
        v == a * c || v == a * d || v == b * c || v == b * d;
*/

/*@
    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;
*/

/*@
    lemma product_bounds:
        \forall integer a, c;
        in_range(a) && in_range(c) ==> product_in_range(a * c);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures is_product(\result, a, b, c, d);
*/
long func(long a, long b, long c, long d)
{
    long tmp[4];
    long max_value;
    int i;

    //@ assert product_in_range(a * c);
    tmp[0] = a * c;
    
    //@ assert product_in_range(a * d);
    tmp[1] = a * d;
    
    //@ assert product_in_range(b * c);
    tmp[2] = b * c;
    
    //@ assert product_in_range(b * d);
    tmp[3] = b * d;

    max_value = tmp[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_value == tmp[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_value >= tmp[k];
        loop invariant \forall integer k; 0 <= k < 4 ==> product_in_range(tmp[k]);
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
