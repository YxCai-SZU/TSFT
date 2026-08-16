#include <stdint.h>

/*@
    predicate N_in_range(integer N) = 3 <= N <= 100;
    predicate N_minus_2_in_range(integer N) = 1 <= N - 2 <= 98;
    predicate result_in_range(integer N, integer result) = 
        180 <= result <= 17640 && result == 180 * (N - 2);
*/

/*@
    requires N_in_range(N);
    ensures \result == 180 * ((int64_t)N - 2);
    ensures result_in_range(N, \result);
*/
int64_t func(uint64_t N)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 3 <= N && N <= 100;
    //@ assert 1 <= N - 2 && N - 2 <= 98;
    //@ assert 180 <= 180 * (N - 2) && 180 * (N - 2) <= 17640;
    
    result = 180 * ((int64_t)N - 2);
    return result;
}
