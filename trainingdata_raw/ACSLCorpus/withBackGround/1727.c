#include <limits.h>

/*@
    predicate in_range(integer n) = -1290 <= n <= 1290;
    logic integer cube(integer n) = n * n * n;
    lemma cube_in_range: \forall integer n; in_range(n) ==> 
        -1290*1290*1290 <= cube(n) <= 1290*1290*1290;
*/

/*@
    requires -1290 <= n <= 1290;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert -1290 <= n <= 1290;
    //@ assert -1290*1290 <= n * n <= 1290*1290;
    //@ assert -1290*1290*1290 <= n * n * n <= 1290*1290*1290;
    
    int cube = n * n * n;
    //@ assert cube == n * n * n;
    return cube;
}
