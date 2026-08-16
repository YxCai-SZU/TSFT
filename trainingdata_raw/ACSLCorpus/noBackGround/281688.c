/*@
    requires (2 <= (k) && (k) <= 100);
    ensures \result == (((k) + 1) / 2);
    assigns \nothing;
*/
int func(int k)
{
    int result;
    int count;
    
    //@ assert (2 <= (k) && (k) <= 100);
    
    result = k + 1;
    count = 0;
    
    /*@
        loop invariant 2 <= k <= 100;
        loop invariant result >= 0;
        loop invariant count >= 0;
        loop invariant result == k + 1 - 2 * count;
        loop invariant count == (k + 1 - result) / 2;
        loop assigns result, count;
        loop variant result;
    */
    while (result > 1)
    {
        //@ assert result > 1;
        
        result = result - 2;
        //@ assert result >= 0;
        
        count = count + 1;
        //@ assert count >= 0;
    }
    
    //@ assert result <= 1;
    //@ assert count == (((k) + 1) / 2);
    
    return count;
}
