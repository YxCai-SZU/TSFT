/*@
predicate is_ordered(integer a, integer b, integer c) =
    b >= a && c >= b;

lemma ordering_implication:
    \forall integer a, b, c;
    is_ordered(a, b, c) ==> (b >= a && c >= b);
*/

/*@
requires a >= -2147483648 && b >= -2147483648 && c >= -2147483648;
requires a <= 2147483647 && b <= 2147483647 && c <= 2147483647;
ensures \result == (b >= a && c >= b);
assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert b >= a && c >= b ==> (b >= a && c >= b);
    result = (b >= a && c >= b);
    return result;
}
