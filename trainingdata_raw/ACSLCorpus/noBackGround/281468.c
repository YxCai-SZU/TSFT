#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100);
    requires (0 <= (a) && (a) <= (N) * (N));
    ensures \result == ((N) * (N)) - a;
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t a) {
    int32_t result;
    
    //@ assert (1 <= (N) && (N) <= 100);
    //@ assert (0 <= (a) && (a) <= (N) * (N));
    //@ assert ((N) * (N)) <= 10000;
    //@ assert ((N) * (N) >= (a));
    
    result = N * N - a;
    return result;
}
