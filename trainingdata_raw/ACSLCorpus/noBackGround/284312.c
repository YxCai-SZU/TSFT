/*@
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
*/
int func(int n)
{
    int original_n = n;
    int is_even = 0;
    
    //@ assert 1 <= original_n <= 100;
    
    if (original_n % 2 == 0)
    {
        is_even = 1;
    }
    else
    {
        is_even = 0;
    }
    
    if (is_even)
    {
        int result = 0;
        int i = 0;
        
        /*@
            loop invariant 0 <= i <= original_n;
            loop invariant result == (3 * (i));
            loop invariant result <= 300;
            loop assigns i, result;
        */
        while (i < original_n)
        {
            //@ assert result == (3 * (i));
            result += 3;
            i += 1;
            //@ assert result == (3 * (i));
        }
        
        //@ assert result == (3 * (original_n));
        return 1;
    }
    else
    {
        return 0;
    }
}
