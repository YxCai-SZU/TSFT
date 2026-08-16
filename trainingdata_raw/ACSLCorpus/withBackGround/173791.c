/*@
    predicate is_in_range(integer k) = 1 <= k <= 50;
    
    logic integer half_k(integer k) = k / 2;
    logic integer remainder(integer k) = k % 2;
    logic integer result_val(integer k) = half_k(k) + remainder(k);
    
    lemma half_k_eq: \forall integer k; is_in_range(k) ==> 
        half_k(k) == (k - remainder(k)) / 2;
        
    lemma result_bound: \forall integer k; is_in_range(k) ==> 
        result_val(k) <= 50;
*/

/*@
    requires is_in_range(k);
    ensures \result == result_val(k);
    assigns \nothing;
*/
unsigned int func(unsigned int k)
{
    unsigned int half_k;
    unsigned int remainder;
    unsigned int result;
    
    //@ assert is_in_range(k);
    
    half_k = k / 2;
    remainder = k % 2;
    
    //@ assert half_k == (k - remainder) / 2;
    
    result = half_k + remainder;
    
    //@ assert result == result_val(k);
    return result;
}
