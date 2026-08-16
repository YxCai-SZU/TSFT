#include <stdint.h>

/*@ requires (1 <= (K) && (K) <= (N) && (N) <= 50);
    ensures \result == ((N) - 1 - ((K) - 1));
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t K) {
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (1 <= (K) && (K) <= (N) && (N) <= 50);
    //@ assert ((N) - 1 - ((K) - 1)) >= 0;
    
    result = N - 1 - (K - 1);
    
    //@ assert result == ((N) - 1 - ((K) - 1));
    //@ assert result >= 0;
    
    return result;
}
