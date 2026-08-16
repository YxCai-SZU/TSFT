/*@
    predicate in_range(integer x) = 1 <= x <= 5000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> product(x, y) <= 25000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == 1 <==> a * b > c * d;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int product1;
    unsigned int product2;
    int result;

    //@ assert in_range(a) && in_range(b);
    product1 = a * b;

    //@ assert in_range(c) && in_range(d);
    product2 = c * d;

    result = (product1 > product2) ? 1 : 0;
    //@ assert result == 1 <==> product1 > product2;
    return result;
}
