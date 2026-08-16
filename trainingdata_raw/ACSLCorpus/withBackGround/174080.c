/*@
    predicate valid_range(integer x) = 1 <= x <= 123;

    lemma subtraction_safe: \forall integer m; 1 <= m <= 123 ==> m - 1 >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) && valid_range(e);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int min;
    min = a;

    if (b < min)
    {
        min = b;
    }

    if (c < min)
    {
        min = c;
    }

    if (d < min)
    {
        min = d;
    }

    if (e < min)
    {
        min = e;
    }

    //@ assert 1 <= min <= 123;
    //@ assert min - 1 >= 0;

    return min - 1;
}
