#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 9;
    
    logic integer cube(integer n) = n * n * n;
    
    lemma cube_in_range: 
        \forall integer n; is_valid_range(n) ==> 1 <= cube(n) && cube(n) <= 729;
*/

/*@
    requires 1 <= n && n <= 9;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert 1 <= n && n <= 9;
    
    //@ assert 1 <= n * n && n * n <= 81;
    
    //@ assert 1 <= n * n * n && n * n * n <= 729;
    
    return n * n * n;
}

/*@
    assigns \nothing;
*/
bool ord(int a0, int a1, int b0, int b1)
{
    return a0 < b0 || (a0 == b0 && a1 < b1);
}
