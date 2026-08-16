/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && 1 <= k && k <= a + b + c;

    lemma cnt_bounds:
        \forall integer a, b, c, k, cnt;
        valid_params(a, b, c, k) && cnt <= a && cnt >= -c ==>
        cnt <= a && cnt >= -c;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a;
    ensures \result >= -c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int kflag;
    int cnt;
    int i;

    kflag = 0;
    cnt = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= a;
        loop invariant 0 <= kflag <= k;
        loop invariant 0 <= cnt <= i;
        loop invariant cnt <= a;
        loop assigns i, kflag, cnt;
        loop variant a - i;
    */
    while (i < a)
    {
        if (kflag == k)
        {
            break;
        }
        //@ assert kflag < k;
        cnt += 1;
        kflag += 1;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= b;
        loop invariant 0 <= kflag <= k;
        loop invariant cnt <= a;
        loop invariant cnt >= 0;
        loop assigns i, kflag;
        loop variant b - i;
    */
    while (i < b)
    {
        if (kflag == k)
        {
            break;
        }
        //@ assert kflag < k;
        kflag += 1;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= c;
        loop invariant 0 <= kflag <= k;
        loop invariant cnt <= a;
        loop invariant cnt >= -i;
        loop assigns i, kflag, cnt;
        loop variant c - i;
    */
    while (i < c)
    {
        if (kflag == k)
        {
            break;
        }
        //@ assert kflag < k;
        cnt -= 1;
        kflag += 1;
        i += 1;
    }

    //@ assert cnt <= a && cnt >= -c;
    return cnt;
}
