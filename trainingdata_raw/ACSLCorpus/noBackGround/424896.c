/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || (a > b * 2 && \result == a - b * 2) || (a <= b * 2 && \result == 0);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    if (a > b * 2)
    {
        //@ assert a > b * 2;
        //@ assert a - b * 2 >= 0;
        result = a - b * 2;
    }
    else
    {
        //@ assert a <= b * 2;
        //@ assert 0 >= 0;
        result = 0;
    }
    
    return result;
}
