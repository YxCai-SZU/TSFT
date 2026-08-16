/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 20 && 1 <= (c) <= 2000);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 20 && 1 <= (c) <= 2000);
    
    x = a + b;
    
    /*@
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 20 && 1 <= (c) <= 2000);
        loop invariant x >= a + b;
        loop assigns x, result;
        loop variant c - x;
    */
    while (x <= c)
    {
        result = c - x;
        //@ assert result >= 0;
        //@ assert result <= c;
        return result;
    }
    
    result = -1;
    //@ assert result == -1;
    return result;
}
