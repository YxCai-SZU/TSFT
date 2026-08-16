/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    predicate result_valid(integer r) =
        r == 0 || r == 1;

    lemma loop_decreases_outer:
        \forall integer m, i; 1 <= i < m ==> m - i > 0;

    lemma loop_decreases_inner:
        \forall integer m, j; 1 <= j < m ==> m - j > 0;
*/

/*@
    requires is_valid_params(n, m);
    ensures result_valid(\result);
*/
int func(unsigned int n, unsigned int m)
{
    int result = 1;
    unsigned int i = 1;
    unsigned int j;

    //@ assert result_valid(result);
    //@ assert 1 <= i <= m;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= m <= n;
        loop invariant m <= 5;
        loop invariant 1 <= i <= m;
        loop invariant result_valid(result);
        loop assigns i, j, result;
        loop variant m - i;
    */
    while (i < m)
    {
        j = i + 1;

        //@ assert i < m;
        //@ assert 1 <= j <= m;

        /*@
            loop invariant 1 <= n <= 100;
            loop invariant 1 <= m <= n;
            loop invariant m <= 5;
            loop invariant i < m;
            loop invariant 1 <= j <= m;
            loop invariant result_valid(result);
            loop assigns j, result;
            loop variant m - j;
        */
        while (j < m)
        {
            //@ assert 1 <= j <= m;
            if (n >= j * 2)
            {
                result = 0;
                //@ assert result_valid(result);
            }
            j += 1;
        }
        i += 1;
    }
    //@ assert result_valid(result);
    return result;
}
