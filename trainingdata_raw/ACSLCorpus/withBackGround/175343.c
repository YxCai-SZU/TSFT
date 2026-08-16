/*@
    predicate valid_params(integer a, integer b, integer x) =
        1 <= a && a <= 1000 &&
        1 <= b && b <= 1000 &&
        1 <= x && x <= 1000;

    logic integer safe_product(integer a, integer b) = (b / a) * a;

    lemma product_bound: \forall integer a, b;
        valid_params(a, b, 1) ==> safe_product(a, b) <= 1000000;
*/

/*@
    requires valid_params(a, b, x);
    ensures \result <= b;
    ensures \result >= 0;
    ensures \result == safe_product(a, b) || \result == b;
    assigns \nothing;
*/
unsigned long func(unsigned long x, unsigned long a, unsigned long b)
{
    // Variable declarations at scope top
    unsigned long product;
    unsigned long result;

    //@ assert a <= 1000;
    //@ assert b / a <= 1000;
    //@ assert safe_product(a, b) <= 1000000;

    product = (b / a) * a;

    if (product < b) {
        result = product;
    } else {
        result = b;
    }

    //@ assert result <= b;
    //@ assert result >= 0;
    //@ assert result == safe_product(a, b) || result == b;

    return result;
}
