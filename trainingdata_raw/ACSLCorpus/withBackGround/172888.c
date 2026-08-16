#include <stdbool.h>

/*@
    predicate valid_params(integer N, integer i) =
        1 <= N <= 100 && 1 <= i <= N;

    logic integer compute_j(integer N, integer i) =
        N - i + 1;

    lemma j_bounds: \forall integer N, i; 
        valid_params(N, i) ==> 1 <= compute_j(N, i) <= N;
*/

/*@
    requires valid_params(N, i);
    ensures 1 <= \result <= N;
    ensures \result == compute_j(N, i);
    assigns \nothing;
*/
int func(int N, int i)
{
    // Variable declarations at top of scope
    int ans;
    
    //@ assert valid_params(N, i);
    
    //@ assert 0 <= N - i;
    //@ assert N - i <= 99;
    
    ans = N - i + 1;
    
    //@ assert ans == compute_j(N, i);
    //@ assert 1 <= ans;
    //@ assert ans <= N;
    
    return ans;
}
