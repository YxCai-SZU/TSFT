/*@
    requires 2 <= n && n <= 100000000000000000;
    ensures \result >= 0;
    assigns \nothing;
*/
long func(unsigned long n)
{
    unsigned long cnt = 1;
    long ans = 0;
    
    /*@
        loop invariant (1 <= (cnt) && (cnt) <= (n) / 2 + 1);
        loop invariant ((ans) >= 0 && (ans) <= (cnt) - 1);
        loop invariant 2 <= n && n <= 100000000000000000;
        loop assigns cnt, ans;
        loop variant n / 2 - cnt + 1;
    */
    while (cnt <= n / 2)
    {
        //@ assert (1 <= (cnt) && (cnt) <= (n) / 2 + 1);
        cnt += 1;
        //@ assert ((ans) >= 0 && (ans) <= (cnt - 1) - 1);
        ans += 1;
        //@ assert ((ans) >= 0 && (ans) <= (cnt) - 1);
    }
    
    //@ assert ((ans) >= 0 && (ans) <= (cnt) - 1);
    //@ assert \forall integer ans, cnt; ((ans) >= 0 && (ans) <= (cnt) - 1) ==> ans >= 0;
    return ans;
}
