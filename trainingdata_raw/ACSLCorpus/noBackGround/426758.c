/*@
    requires (1 <= (n) && (n) <= 23);
    ensures \result == (48 - (n));
    assigns \nothing;
*/
int func(unsigned int n)
{
    int result;
    
    //@ assert (48 - (n)) == 48 - (int)n;
    result = 48 - (int)n;
    
    return result;
}
