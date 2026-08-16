#include <stddef.h>

/*@
    predicate is_valid_k(integer k) = 1 <= k && k <= 200;
    
    logic integer func_spec(integer k) = (k / 2) * ((k + 1) / 2);
    
    lemma func_bounds: \forall integer k; is_valid_k(k) ==> 
        k / 2 <= 100 && (k + 1) / 2 <= 100 && func_spec(k) <= 10000;
*/

/*@
    requires is_valid_k(k);
    ensures \result == func_spec(k);
    assigns \nothing;
*/
size_t func(size_t k)
{
    // Variable declarations at top of scope
    size_t result;
    
    // Precondition verification
    //@ assert k >= 1;
    //@ assert k <= 200;
    
    // Arithmetic bounds verification
    //@ assert k / 2 <= 100;
    //@ assert (k + 1) / 2 <= 100;
    //@ assert (k / 2) * ((k + 1) / 2) <= 10000;
    
    result = (k / 2) * ((k + 1) / 2);
    
    // Postcondition verification
    //@ assert result == func_spec(k);
    
    return result;
}

int main(void)
{
    return 0;
}
