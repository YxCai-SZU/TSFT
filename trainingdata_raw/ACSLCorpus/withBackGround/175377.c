/*@
    predicate bounds(integer n, integer a, integer b) =
        1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50;

    logic integer product(integer n, integer a) = n * a;

    lemma product_bound: \forall integer n, integer a;
        bounds(n, a, 0) ==> product(n, a) <= 1000;
*/

/*@
    requires bounds(n, a, b);
    ensures \result == product(n, a) || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int a, unsigned int b)
{
    // Variable declarations at the top
    unsigned int product;
    unsigned int result;

    //@ assert bounds(n, a, b);
    //@ assert product(n, a) <= 1000;

    product = n * a;

    if (product < b)
    {
        //@ assert product(n, a) < b;
        //@ assert product(n, a) <= b;
        result = product;
    }
    else
    {
        //@ assert product(n, a) >= b;
        result = b;
    }

    //@ assert result == product(n, a) || result == b;
    //@ assert result <= b;
    return result;
}
