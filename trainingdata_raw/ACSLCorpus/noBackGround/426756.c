/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Declare all variables at the top
    int result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 2 <= m && m <= 100;
    
    //@ assert 1 <= n - 1;
    //@ assert 1 <= m - 1;
    
    //@ assert (n - 1) * (m - 1) <= 9801;
    //@ assert 1 <= (n - 1) * (m - 1);
    
    result = (n - 1) * (m - 1);
    
    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
