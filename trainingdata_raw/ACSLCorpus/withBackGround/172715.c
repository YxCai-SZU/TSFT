/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= product(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int count;
    
    //@ assert valid_range(a, b);
    x = a * b;
    count = 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant x >= 0;
        loop invariant x <= product(a, b);
        loop invariant count >= 0;
        loop invariant count <= (product(a, b) - x) / 10;
        loop assigns x, count;
        loop variant x;
    */
    while (x >= 10)
    {
        x -= 10;
        count += 1;
    }

    if (x > 0)
    {
        count += 1;
    }

    //@ assert count >= 0;
    //@ assert count <= product(a, b);
    return count;
}
