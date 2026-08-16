#include <limits.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 9;

    lemma square_bounds: \forall integer n; is_valid_range(n) ==> 1 <= n * n <= 81;
    lemma cube_bounds: \forall integer n; is_valid_range(n) ==> 1 <= n * n * n <= 729;
    lemma cube_identity: \forall integer n, x, y; 
        is_valid_range(n) && x == n * n && y == x * n ==> y == n * n * n;
*/

/*@
    requires is_valid_range(n);
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int x;
    int y;
    
    //@ assert is_valid_range(n);
    
    //@ assert 1 <= n * n && n * n <= 81;
    x = n * n;
    
    //@ assert 1 <= x * n && x * n <= 729;
    y = x * n;
    
    //@ assert y == n * n * n;
    return y;
}
