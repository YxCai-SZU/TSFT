#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 9;
    
    logic integer cube(integer n) = n * n * n;
    
    lemma cube_bounds:
        \forall integer n; is_valid_n(n) ==> 1 <= cube(n) && cube(n) <= 729;
*/

/*@
    requires is_valid_n(n);
    ensures \result == cube(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert is_valid_n(n);
    
    //@ assert 1 <= n * n && n * n <= 81;
    
    //@ assert 1 <= n * n * n && n * n * n <= 729;
    
    result = n * n * n;
    
    //@ assert result == cube(n);
    
    return result;
}
