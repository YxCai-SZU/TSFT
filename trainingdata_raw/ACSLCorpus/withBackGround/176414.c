#include <stdint.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
    logic integer max_of_four(integer ac, integer ad, integer bc, integer bd) =
        (ac >= ad && ac >= bc && ac >= bd) ? ac :
        (ad >= bc && ad >= bd) ? ad :
        (bc >= bd) ? bc : bd;
    lemma product_range_lemma:
        \forall integer a, integer c;
            in_range(a) && in_range(c) ==> product_in_range(a, c);
    lemma product_range_lemma2:
        \forall integer a, integer d;
            in_range(a) && in_range(d) ==> product_in_range(a, d);
    lemma product_range_lemma3:
        \forall integer b, integer c;
            in_range(b) && in_range(c) ==> product_in_range(b, c);
    lemma product_range_lemma4:
        \forall integer b, integer d;
            in_range(b) && in_range(d) ==> product_in_range(b, d);
    lemma max_is_one_of:
        \forall integer ac, integer ad, integer bc, integer bd;
            max_of_four(ac, ad, bc, bd) == ac ||
            max_of_four(ac, ad, bc, bd) == ad ||
            max_of_four(ac, ad, bc, bd) == bc ||
            max_of_four(ac, ad, bc, bd) == bd;
*/

/*@
    requires
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        a <= b && c <= d;
    ensures
        \result == b * d || \result == a * c || \result == a * d || \result == b * c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ans[4];
    int64_t max_val;
    int i;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    //@ assert product_in_range(a, c);
    //@ assert product_in_range(a, d);
    //@ assert product_in_range(b, c);
    //@ assert product_in_range(b, d);

    ans[0] = a * c;
    ans[1] = a * d;
    ans[2] = b * c;
    ans[3] = b * d;

    max_val = ans[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == ans[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= ans[j];
        loop invariant in_range(a) && in_range(b) && in_range(c) && in_range(d);
        loop invariant a <= b && c <= d;
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (ans[i] > max_val)
        {
            max_val = ans[i];
        }
        i = i + 1;
    }

    //@ assert max_val == max_of_four(a*c, a*d, b*c, b*d);
    //@ assert max_val == b*d || max_val == a*c || max_val == a*d || max_val == b*c;

    return max_val;
}
