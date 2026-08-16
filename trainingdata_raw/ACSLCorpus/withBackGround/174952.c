/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer product_mod2(integer a, integer b) = (a * b) % 2;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 1 <= a * b <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == product_mod2(a, b);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= a * b <= 10000;

    product = a * b;

    if (product % 2 == 0) {
        result = 0;
    } else {
        result = 1;
    }

    //@ assert result == product_mod2(a, b);
    return result;
}
