/*@
    predicate is_valid_array(integer n, int *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        (\forall integer k; 0 <= k < n ==> p[k] >= 1 && p[k] <= n) &&
        (\forall integer k, l; 0 <= k < l < n ==> p[k] != p[l]);

    lemma count_bounds:
        \forall integer n, int *p, integer count;
        is_valid_array(n, p) && 1 <= count <= n ==> count >= 1 && count <= n;
*/

/*@
    requires is_valid_array(n, p);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p)
{
    int count = 1;
    int i = 1;
    int j;
    int pi;
    int min;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant 1 <= count <= i;
        loop invariant is_valid_array(n, p);
        loop assigns i, count, j, pi, min;
        loop variant n - i;
    */
    while (i < n)
    {
        pi = p[i];
        min = p[0];
        j = 0;

        /*@
            loop invariant 0 <= j <= i;
            loop invariant \forall integer k; 0 <= k < j ==> p[k] >= min;
            loop invariant \exists integer k; 0 <= k < i && p[k] == min;
            loop assigns j, min;
            loop variant i - j;
        */
        while (j < i)
        {
            //@ assert 0 <= j < n;
            if (p[j] < min)
            {
                min = p[j];
            }
            j += 1;
        }

        //@ assert \forall integer k; 0 <= k < i ==> p[k] >= min;
        if (pi < min)
        {
            count += 1;
        }
        i += 1;
    }

    //@ assert count >= 1 && count <= n;
    return count;
}
