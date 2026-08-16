/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert a + b + c <= 100 + 100 + 100;
    
    int result;
    result = a + b + c;
    
    //@ assert result == a + b + c;
    return result;
}
