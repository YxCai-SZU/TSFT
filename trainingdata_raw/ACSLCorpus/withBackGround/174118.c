/*@
    predicate nonnegative(integer x) = x >= 0;

    lemma calc_example_4: \forall integer x; nonnegative(x) ==> 2 * x - x == x * 1;
    lemma example_commutative_add: \forall integer a, b; nonnegative(a) && nonnegative(b) ==> a + b == b + a;
    lemma example_assocative_add: \forall integer a, b, c; nonnegative(a) && nonnegative(b) && nonnegative(c) ==> (a + b) + c == a + (b + c);
*/

int main()
{
    return 0;
}
