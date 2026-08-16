/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_in_range: \forall integer a, b;
        valid_range(a, b) ==> 1 <= product(a, b) && product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
long func(long a, long b)
{
    //@ assert valid_range(a, b);
    //@ assert 1 <= product(a, b) && product(a, b) <= 10000;
    //@ assert product(a, b) == product(a, b);
    return a * b;
}
