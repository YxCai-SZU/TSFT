/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) <= (a));
    ensures ((a) - (b) * 2 > 0 ==> (\result) == (a) - (b) * 2);
    ensures ((a) - (b) * 2 <= 0 ==> (\result) == 0);
*/
int func(int a, int b)
{
    int ans;
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    if (a - b * 2 > 0)
    {
        ans = a - b * 2;
        //@ assert ans == a - b * 2;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ((ans) >= 0);
    //@ assert ((ans) <= (a));
    //@ assert ((a) - (b) * 2 > 0 ==> (ans) == (a) - (b) * 2);
    //@ assert ((a) - (b) * 2 <= 0 ==> (ans) == 0);
    
    return ans;
}
