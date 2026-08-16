/*@
    requires (0 <= (a) && (a) < 24 && 0 <= (b) && (b) < 24);
    ensures \result == ((a + b) % 24);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int c;
    unsigned int result;
    
    //@ assert (0 <= (a) && (a) < 24 && 0 <= (b) && (b) < 24);
    
    c = a + b;
    
    if (c < 24)
    {
        result = c;
    }
    else
    {
        result = c - 24;
    }
    
    //@ assert result == ((a + b) % 24);
    
    return result;
}
