/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= (n));
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    // Variable declarations at scope top
    unsigned int result;
    
    // Precondition ensures no underflow/overflow
    //@ assert n - k >= 0;
    //@ assert n - k + 1 <= 100;
    
    result = n - k + 1;
    
    // Postcondition verification
    //@ assert result == ((n) - (k) + 1);
    
    return result;
}
