/*@
    requires 1 <= n <= 100;
    ensures (n % 2 == 1 ==> \result == 1) && 
            (n % 2 == 0 ==> \result == (800 - (n / 2) * 200));
    assigns \nothing;
*/
int func(int n)
{
    int result;
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 1)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        result = 800 - (n / 2) * 200;
        //@ assert result == 800 - (n / 2) * 200;
    }
    
    return result;
}
