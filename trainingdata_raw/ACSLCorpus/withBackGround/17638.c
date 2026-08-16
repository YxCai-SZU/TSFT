/*@
    predicate is_even_property(integer i, integer is_even) =
        is_even == (i % 2 == 1);
*/

/*@
    logic integer decreases_term(integer n, integer i) = n - i;
*/

/*@
    lemma loop_decreases:
        \forall integer n, i;
            1 <= n <= 100 && 1 <= i <= n ==> decreases_term(n, i) >= 0;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int n)
{
    int is_even;
    int i;
    int result;

    is_even = 1;
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant is_even_property(i, is_even);
        loop assigns i, is_even;
        loop variant n - i;
    */
    while (i < n)
    {
        if (is_even)
        {
            is_even = 0;
        }
        else
        {
            is_even = 1;
        }
        i = i + 1;
    }

    if (is_even)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
