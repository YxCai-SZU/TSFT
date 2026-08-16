#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == (((N) * 800) - ((((N)) / 15) * 200));
    assigns \nothing;
*/
int64_t func(int64_t N) {
    int64_t result;
    int64_t count;
    int64_t temp_N;
    
    result = N * 800;
    count = 0;
    temp_N = N;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant count >= 0;
        loop invariant N == temp_N + 15 * count;
        loop invariant count <= ((N) / 15);
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 15) {
        temp_N -= 15;
        count += 1;
    }
    
    /*@ assert count == ((N) / 15); */
    
    result -= count * 200;
    
    /*@ assert result == (((N) * 800) - ((((N)) / 15) * 200)); */
    
    return result;
}
