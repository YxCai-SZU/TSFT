#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n && n <= 65535;
    
    logic integer triangular_number_spec(integer n) = n * (n + 1) / 2;
    
    lemma triangular_number_bound: 
        \forall integer n; is_valid_n(n) ==> triangular_number_spec(n) <= 2147483647;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_number_spec(n);
    assigns \nothing;
*/
uint32_t triangular_number(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ret;
    
    //@ assert is_valid_n(n);
    
    //@ assert triangular_number_spec(n) <= 2147483647;
    
    ret = n * (n + 1) / 2;
    
    //@ assert ret == triangular_number_spec(n);
    
    return ret;
}

int main(void)
{
    return 0;
}
