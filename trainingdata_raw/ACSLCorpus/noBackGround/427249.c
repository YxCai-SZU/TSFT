/*@
    requires ((x) >= 0 && (y) >= 0 && (x) * (y) <= 4294967295);
    ensures \result == x * y;
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert ((x) >= 0 && (y) >= 0 && (x) * (y) <= 4294967295);
    
    //@ assert x * y >= 0;
    
    result = x * y;
    
    //@ assert result == x * y;
    
    return result;
}
