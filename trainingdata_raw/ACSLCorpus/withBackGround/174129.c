/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    lemma product_bounds: \forall integer a, b; bounds(a, b) ==> a * b <= 10000;
    lemma product_no_overflow: \forall integer a, b; bounds(a, b) ==> a * b <= 2147483647;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert bounds(a, b);
    //@ assert a * b <= 10000;
    //@ assert a * b <= 2147483647;
    return a * b;
}
