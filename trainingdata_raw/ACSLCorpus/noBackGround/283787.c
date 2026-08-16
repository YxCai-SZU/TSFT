/*@
    requires (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
    ensures (1 <= n && n <= 9) ==> \result == 2 * n + (m - 1) * 4;
    ensures (10 <= n && n <= 20) ==> \result == 20 + (m - 1) * 2;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    if (n < 10)
    {
        result = 2 * n + (m - 1) * 4;
        //@ assert 1 <= n && n <= 9;
        //@ assert result == ((1 <= (n) && (n) <= 9) ? (2 * (n) + ((m) - 1) * 4) :         (10 <= (n) && (n) <= 20) ? (20 + ((m) - 1) * 2) : 0);
        return result;
    }
    else
    {
        result = 20 + (m - 1) * 2;
        int i = 0;
        
        /*@
            loop invariant 0 <= i <= 1;
            loop invariant (1 <= (n) && (n) <= 20 && 1 <= (m) && (m) <= 20);
            loop invariant result == 20 + (m - 1) * 2;
            loop assigns i;
        */
        while (i < 1)
        {
            i = i + 1;
        }
        
        //@ assert 10 <= n && n <= 20;
        //@ assert result == ((1 <= (n) && (n) <= 9) ? (2 * (n) + ((m) - 1) * 4) :         (10 <= (n) && (n) <= 20) ? (20 + ((m) - 1) * 2) : 0);
        return result;
    }
}
