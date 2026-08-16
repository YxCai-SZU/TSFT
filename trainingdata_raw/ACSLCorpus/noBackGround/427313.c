/*@
requires 1 <= n && n <= 100;
ensures (((n) % 2 == 0) ==> \result == 1) && (((n) % 2 != 0) ==> \result == 1);
assigns \nothing;
*/
int func(int n)
{
    int ans;
    int i;
    
    ans = 1;
    i = 1;
    
    /*@
    loop invariant 1 <= i && i <= n;
    loop invariant ans == 1;
    loop invariant (((i) % 2 == 0) ==> ans == 1) && (((i) % 2 != 0) ==> ans == 1);
    loop assigns i, ans;
    loop variant n - i;
    */
    while (i < n)
    {
        //@ assert ans == 1;
        ans = 1;
        i = i + 1;
    }
    
    //@ assert (((n) % 2 == 0) ==> ans == 1) && (((n) % 2 != 0) ==> ans == 1);
    return ans;
}
