#include <limits.h>

/*@
    predicate is_valid_param(integer x) = 1 <= x <= 100;

    logic integer max_of_four(integer ac, integer ad, integer bc, integer bd) =
        (ac >= ad && ac >= bc && ac >= bd) ? ac :
        (ad >= bc && ad >= bd) ? ad :
        (bc >= bd) ? bc : bd;

    lemma max_ge_ac: \forall integer ac, ad, bc, bd;
        max_of_four(ac, ad, bc, bd) >= ac;
    lemma max_ge_ad: \forall integer ac, ad, bc, bd;
        max_of_four(ac, ad, bc, bd) >= ad;
    lemma max_ge_bc: \forall integer ac, ad, bc, bd;
        max_of_four(ac, ad, bc, bd) >= bc;
    lemma max_ge_bd: \forall integer ac, ad, bc, bd;
        max_of_four(ac, ad, bc, bd) >= bd;

    lemma max_is_one_of: \forall integer ac, ad, bc, bd;
        max_of_four(ac, ad, bc, bd) == ac ||
        max_of_four(ac, ad, bc, bd) == ad ||
        max_of_four(ac, ad, bc, bd) == bc ||
        max_of_four(ac, ad, bc, bd) == bd;
*/

/*@
    requires is_valid_param(a);
    requires is_valid_param(b);
    requires is_valid_param(c);
    requires is_valid_param(d);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_value;
    int ac;
    int ad;
    int bc;
    int bd;

    //@ assert is_valid_param(a);
    //@ assert is_valid_param(b);
    //@ assert is_valid_param(c);
    //@ assert is_valid_param(d);

    ac = a * c;
    ad = a * d;
    bc = b * c;
    bd = b * d;

    //@ assert ac <= 10000;
    //@ assert ad <= 10000;
    //@ assert bc <= 10000;
    //@ assert bd <= 10000;

    max_value = ac;

    if (ad > max_value)
    {
        max_value = ad;
    }

    if (bc > max_value)
    {
        max_value = bc;
    }

    if (bd > max_value)
    {
        max_value = bd;
    }

    //@ assert max_value == ac || max_value == ad || max_value == bc || max_value == bd;
    return max_value;
}
