/*@
predicate positive_and_bounded(integer v) = v > 0 && v <= 10000;

lemma multiplication_commutative:
    \forall integer a, b;
        positive_and_bounded(a) && positive_and_bounded(b) ==>
        a * b == b * a;
*/

/*@
    requires positive_and_bounded(a) && positive_and_bounded(b);
    ensures \result == b * a;
*/
int non_linear_arith_example(int a, int b)
{
    //@ assert positive_and_bounded(a);
    //@ assert positive_and_bounded(b);
    //@ assert a * b <= 100000000;
    //@ assert a * b == b * a;
    return a * b;
}
