/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    lemma product_bounds:
        \forall integer a, b;
            is_valid_range(a, b) ==>
            a * b >= 1 && a * b <= 10000;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int c;
    //@ assert is_valid_range(a, b);
    //@ assert a * b >= 1 && a * b <= 10000;
    c = a;
    //@ assert c == a;
    //@ assert c * b >= 1 && c * b <= 10000;
    return c * b;
}
