/*@
    requires (400 <= (X) && (X) < 2000);
    ensures (1 <= (\result) && (\result) <= 8);
    assigns \nothing;
*/
int func(int X)
{
    int ans;
    int i;
    int Xj;
    
    ans = 8;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (400 <= (X) && (X) < 2000);
        loop invariant (1 <= (ans) && (ans) <= 8);
        loop assigns i, ans, Xj;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        Xj = 200 + 200 * i;
        
        //@ assert Xj == 200 * (i + 1);
        
        if (X >= Xj)
        {
            ans = 8 - i;
        }
        
        i += 1;
    }
    
    //@ assert (1 <= (ans) && (ans) <= 8);
    return ans;
}

int main()
{
    return 0;
}
