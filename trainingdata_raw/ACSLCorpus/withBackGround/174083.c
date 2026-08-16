#include <stdint.h>

/*@
    predicate in_range(integer n) = -1290 <= n && n <= 1290;
    
    logic integer cube(integer n) = n * n * n;
    
    lemma cube_range: \forall integer n; in_range(n) ==> 
        -1290*1290*1290 <= cube(n) && cube(n) <= 1290*1290*1290;
*/

/*@
    requires in_range(n);
    ensures \result == cube(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Declare all variables at the top
    int64_t result;
    
    //@ assert in_range(n);
    
    //@ assert -1290*1290 <= n*n && n*n <= 1290*1290;
    
    //@ assert -1290*1290*1290 <= n*n*n && n*n*n <= 1290*1290*1290;
    
    result = n * n * n;
    
    //@ assert result == cube(n);
    
    return result;
}
