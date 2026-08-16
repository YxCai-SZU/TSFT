/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;

    logic integer func_spec(integer r) = 3 * r * r;

    lemma func_bound: \forall integer r; r_in_range(r) ==> func_spec(r) <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
unsigned int func(unsigned int r)
{
    // Variable declarations
    unsigned int result;

    // Precondition assertions
    //@ assert 1 <= r;
    //@ assert r <= 100;
    
    // Upper bound for 3 * r
    //@ assert 3 * 100 >= 3 * r;
    
    // Lower bound for 3 * r
    //@ assert 3 * 1 <= 3 * r;
    
    // Upper bound for 3 * r * r
    //@ assert 3 * 100 * 100 >= 3 * r * r;
    
    // Final computation
    result = 3 * r * r;
    
    // Postcondition verification
    //@ assert result == 3 * r * r;
    
    return result;
}
