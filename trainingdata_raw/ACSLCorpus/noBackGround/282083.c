/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    int remainder;
    
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    result = n;
    remainder = m;
    
    /*@
        loop invariant 0 <= result <= n;
        loop invariant 0 <= remainder <= m;
        loop invariant result == n - 2 * (m - remainder);
        loop assigns result, remainder;
    */
    while (remainder > 0)
    {
        //@ assert remainder > 0;
        
        if (result >= 2 && remainder >= 1)
        {
            result -= 2;
            remainder -= 1;
        }
        else
        {
            break;
        }
    }
    
    //@ assert 0 <= result <= n;
    return result;
}
