#include <limits.h>

/*@
    predicate in_range(integer n) = -1290 <= n <= 1290;
    predicate square_in_range(integer n) = -1290*1290 <= n*n <= 1290*1290;
    predicate cube_in_range(integer n) = -1290*1290*1290 <= n*n*n <= 1290*1290*1290;
    
    lemma square_bound: \forall integer n; in_range(n) ==> square_in_range(n);
    lemma cube_bound: \forall integer n; in_range(n) ==> cube_in_range(n);
*/

/*@
    requires -1290 <= n <= 1290;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top
    int n_squared;
    int n_cubed;
    
    //@ assert -1290 <= n <= 1290;
    
    //@ assert -1290*1290 <= n*n <= 1290*1290;
    
    //@ assert -1290*1290*1290 <= n*n*n <= 1290*1290*1290;
    
    n_squared = n * n;
    n_cubed = n_squared * n;
    
    return n_cubed;
}
