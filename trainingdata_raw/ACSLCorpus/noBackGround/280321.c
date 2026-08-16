#include <stdint.h>

/*@
    requires 1 <= N <= 100;
    ensures \result >= 0 && \result == (N + 1) / 2;
*/
int32_t func(uint32_t N)
{
    uint32_t i = 0;
    int32_t count = 0;
    
    //@ assert (0 <= (i) <= (N) &&         1 <= (N) <= 100 &&         (count) >= 0 &&         (count) == ((i) + 1) / 2);
    
    /*@
        loop invariant (0 <= (i) <= (N) &&
        1 <= (N) <= 100 &&
        (count) >= 0 &&
        (count) == ((i) + 1) / 2);
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N) {
        if (i % 2 == 0) {
            count += 1;
        }
        i += 1;
        
        //@ assert (0 <= (i) <= (N) &&         1 <= (N) <= 100 &&         (count) >= 0 &&         (count) == ((i) + 1) / 2);
    }
    
    //@ assert i == N;
    //@ assert count == (N + 1) / 2;
    
    return count;
}
