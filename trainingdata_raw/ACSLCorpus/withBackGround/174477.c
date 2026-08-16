/*@
    predicate valid_range(integer a, integer b, integer c) =
        a >= 1 && a <= 100 &&
        b >= 1 && b <= 100 &&
        c >= 1 && c <= 100;

    logic integer product(integer a, integer b, integer c) = a * b * c;

    lemma product_bounds:
        \forall integer a, b, c;
        valid_range(a, b, c) ==> product(a, b, c) >= 0 && product(a, b, c) <= 1000000;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result >= 0 && \result <= a * b * c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert a * b <= 10000;
    //@ assert a * b * c <= 1000000;
    return a * b * c;
}
