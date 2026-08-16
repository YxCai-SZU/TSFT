/*@
    requires (1 <= (a) <= 500) && (1 <= (b) <= 500) && (1 <= (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert (1 <= (a) <= 500);
    //@ assert (1 <= (b) <= 500);
    //@ assert (1 <= (c) <= 1000);
    
    result = (a + b >= c);
    
    //@ assert result == (a + b >= c);
    return result;
}
