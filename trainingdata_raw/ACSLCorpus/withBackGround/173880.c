/*@
    predicate is_in_range(integer n) = -40 <= n && n <= 40;
    predicate is_ge_30(integer n) = n >= 30;
*/

/*@
    requires is_in_range(n);
    ensures \result == (n >= 30);
    assigns \nothing;
*/
_Bool func(int n)
{
    int i;

    if (n < 30)
    {
        i = 0;
        /*@
            loop invariant is_in_range(n);
            loop invariant 0 <= i && i <= 10000000;
            loop invariant n < 30;
            loop assigns i;
            loop variant 10000000 - i;
        */
        while (i < 10000000)
        {
            //@ assert is_in_range(n);
            i = i + 1;
        }
        //@ assert n < 30;
        return 0;
    }
    else
    {
        i = 0;
        /*@
            loop invariant is_in_range(n);
            loop invariant 0 <= i && i <= 10000000;
            loop invariant n >= 30;
            loop assigns i;
            loop variant 10000000 - i;
        */
        while (i < 10000000)
        {
            //@ assert is_in_range(n);
            i = i + 1;
        }
        //@ assert n >= 30;
        return 1;
    }
}
