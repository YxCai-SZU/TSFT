/*@
    predicate pos(integer x) = x > 0;

    lemma mul_comm:
        \forall integer a, b; pos(a) && pos(b) ==> a * b == b * a;

    lemma mul_assoc:
        \forall integer a, b, c; pos(a) && pos(b) && pos(c) ==> a * (b * c) == (a * b) * c;

    lemma mul_assoc_comm:
        \forall integer a, b, c; pos(a) && pos(b) && pos(c) ==> a * b * c == a * c * b;
*/

/*@
    requires a > 0 && b > 0;
    ensures \result > 0;
    ensures \result == a * b;
    assigns \nothing;
*/
int non_linear_arith_example9(int a, int b)
{
    //@ assert a * b > 0;
    return a * b;
}
