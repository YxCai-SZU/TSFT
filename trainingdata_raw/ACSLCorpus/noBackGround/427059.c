/*@
    requires ((a) + (b) + (c) <= 0 && (c) >= 0);
    ensures \result == a + b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert a + b + c <= 0;
    //@ assert c >= 0;
    //@ assert a + b <= 0;
    
    int result = a + b;
    //@ assert result == a + b;
    return result;
}
