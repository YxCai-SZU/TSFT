/*@
    requires (2 <= (k) <= 100);
    ensures \result == (((k) + 1) / 2);
    assigns \nothing;
*/
int func(int k)
{
    int result;
    int count;
    
    result = k + 1;
    count = 0;
    
    /*@
        loop invariant 0 <= result <= k + 1;
        loop invariant 0 <= count <= (k + 1) / 2;
        loop invariant result == k + 1 - 2 * count;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        //@ assert result >= 2;
        result -= 2;
        count += 1;
    }
    
    //@ assert count == (((k) + 1) / 2);
    return count;
}
