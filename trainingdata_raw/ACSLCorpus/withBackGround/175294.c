/*@
predicate leq(integer a, integer b) = a <= b;

lemma transitivity:
    \forall integer a, b, c;
        leq(a, b) && leq(b, c) ==> leq(a, c);

lemma equality:
    \forall integer n;
        n == n ==> n == n;

logic integer triple(integer n) = n * 3;

lemma calc_example_6:
    \forall integer n;
        n == 10 ==> triple(n) <= 60;
*/

/*@
    requires n == 10;
    ensures \result == 30;
    assigns \nothing;
*/
int example(int n)
{
    int result;
    //@ assert n == 10;
    result = n * 3;
    //@ assert result == 30;
    //@ assert result <= 60;
    return result;
}

int main()
{
    int x = 10;
    int y = example(x);
    return 0;
}
