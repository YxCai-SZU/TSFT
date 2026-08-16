#include <stdint.h>

/*@
    predicate valid_range(integer N) = 1 <= N <= 1000000000;
    
    logic integer half_plus_remainder(integer N) = N / 2 + N % 2;
    
    lemma arithmetic_bounds:
        \forall integer N; valid_range(N) ==> 
            N / 2 <= 500000000 && N / 2 + N % 2 <= 1000000000;
*/

/*@
    requires valid_range(N);
    ensures \result == half_plus_remainder(N);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    // Variable declarations at scope top
    uint64_t ans;
    
    //@ assert N / 2 <= 500000000;
    //@ assert N / 2 + N % 2 <= 1000000000;
    
    ans = N / 2 + N % 2;
    
    return ans;
}

int main()
{
    return 0;
}
