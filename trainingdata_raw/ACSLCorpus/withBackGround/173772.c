/*@
    predicate is_valid_range(integer k, integer a, integer b) =
        1 <= k <= 1000 && 1 <= a <= b <= 1000;

    logic integer product_bound(integer k, integer b_div_k) =
        b_div_k * k;

    lemma product_bound_lemma:
        \forall integer k, integer b, integer b_div_k;
        is_valid_range(k, 1, b) && b_div_k == b / k ==>
        product_bound(k, b_div_k) <= 1000000;
*/

/*@
    requires is_valid_range(k, a, b);
    ensures \result == ((b / k) * k >= a);
    assigns \nothing;
*/
_Bool func(unsigned long k, unsigned long a, unsigned long b)
{
    unsigned long b_div_k;
    _Bool result;

    b_div_k = b / k;

    //@ assert product_bound(k, b_div_k) <= 1000000;

    result = (b_div_k * k >= a);
    return result;
}
