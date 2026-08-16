/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - 2 * (b)) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    
    ans = a - 2 * b;
    
    //@ assert ans == ((a) - 2 * (b));
    
    if (ans < 0)
    {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans == ((a) - 2 * (b)) || ans == 0;
    
    return ans;
}
