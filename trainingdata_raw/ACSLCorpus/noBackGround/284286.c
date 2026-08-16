/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
 */
int func(int a, int b, int c)
{
    int result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    if (a < b && b < c)
    {
        //@ assert ((a) < (b) && (b) < (c));
        result = 1;
    }
    else
    {
        //@ assert !((a) < (b) && (b) < (c));
        result = 0;
    }
    
    return result;
}
