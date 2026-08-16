/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer product(integer k) = k * 500;

    lemma product_bound: \forall integer k; 1 <= k <= 100 ==> product(k) <= 50000;
*/

/*@
    requires valid_params(k, x);
    ensures \result == (product(k) >= x);
    assigns \nothing;
*/
_Bool func(int k, int x)
{
    // Variable declarations at scope top
    int en;
    int product;
    _Bool result;

    en = 500;

    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    //@ assert product(k) <= 50000;

    product = k * en;

    if (product >= x) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}
