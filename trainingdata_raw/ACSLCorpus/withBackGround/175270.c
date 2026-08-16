/*@
    predicate is_valid_k(integer k) = 0 <= k && k < 3;
    
    logic integer cube(integer k) = k * k * k;
    
    lemma k_square_bound: \forall integer k; is_valid_k(k) ==> k * k < 9;
    lemma k_cube_bound: \forall integer k; is_valid_k(k) ==> k * k * k < 27;
*/

/*@
    requires is_valid_k(k);
    ensures \result == cube(k);
    assigns \nothing;
*/
unsigned int func(unsigned int k)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert 0 <= k && k < 3;
    
    //@ assert k * k < 9;
    
    //@ assert k * k * k < 27;
    
    result = k * k * k;
    
    //@ assert result == cube(k);
    
    return result;
}

int main(void)
{
    return 0;
}
