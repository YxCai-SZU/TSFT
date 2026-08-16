/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((ls) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (ls)[j] && (ls)[j] <= 100);
    ensures 1 <= \result && \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int* ls)
{
    int ans = 1;
    int ds = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((ls) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (ls)[j] && (ls)[j] <= 100 &&
        1 <= (ans) && (ans) <= (i) + 1 &&
        0 <= (ds) && (ds) <= (i) * 100 &&
        \forall integer k; 0 <= k < (i) ==> (ds) >= (ls)[k]);
        loop assigns i, ans, ds;
        loop variant n - i;
    */
    while (i < n)
    {
        int l = ls[i];
        ds += l;
        
        //@ assert ds >= l;
        
        if (ds <= x)
        {
            ans += 1;
        }
        
        i += 1;
    }
    
    //@ assert 1 <= ans && ans <= n + 1;
    return ans;
}
