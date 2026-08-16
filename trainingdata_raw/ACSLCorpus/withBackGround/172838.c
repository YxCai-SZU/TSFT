/*@
    predicate is_valid_input(integer a, integer b, integer c, integer d) =
        a >= 1 && b >= 1 && c >= 1 && d >= 1 &&
        a <= 10000 && b <= 10000 && c <= 10000 && d <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer a, b;
        a >= 1 && a <= 10000 && b >= 1 && b <= 10000 ==>
        product(a, b) <= 10000 * 10000;
*/

/*@
    requires is_valid_input(a, b, c, d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
*/
int func(int a, int b, int c, int d)
{
    int s1;
    int s2;
    int ans;

    //@ assert product(a, b) <= 10000 * 10000;
    //@ assert product(c, d) <= 10000 * 10000;

    s1 = a * b;
    s2 = c * d;

    if (s1 >= s2)
    {
        ans = s1;
    }
    else
    {
        ans = s2;
    }

    return ans;
}
