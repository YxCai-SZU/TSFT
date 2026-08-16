/*@
    requires (3 <= (n) && (n) <= 32767);
    ensures \result == (((n) - 2) * ((n) - 1) / 2);
    assigns \nothing;
*/
unsigned int count_triangles(unsigned int n)
{
    // Variable declarations at scope top
    unsigned int result;
    
    // Precondition assertions
    //@ assert n >= 3;
    //@ assert n <= 32767;
    
    // Overflow safety lemma application
    //@ assert (((n) - 2) * ((n) - 1) / 2) <= 32767 * 32767 / 2;
    
    result = (n - 2) * (n - 1) / 2;
    
    // Postcondition verification
    //@ assert result == (((n) - 2) * ((n) - 1) / 2);
    
    return result;
}
