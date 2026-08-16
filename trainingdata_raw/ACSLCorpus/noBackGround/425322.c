#include <stdint.h>

/*@
    requires (1 <= (N) <= 100);
    ensures \result == (800 * (N) - 200 * ((N) / 15));
*/
int64_t func(int64_t N)
{
    // Variable declarations at scope top
    int64_t result;
    int64_t count;
    int64_t temp_N;
    
    //@ assert (1 <= (N) <= 100);
    result = 800 * N;
    count = 0;
    temp_N = N;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count <= N / 15;
        loop invariant temp_N == N - 15 * count;
        loop invariant result == 800 * N;
        loop assigns count, temp_N;
    */
    while (temp_N >= 15)
    {
        //@ assert temp_N >= 15;
        count = count + 1;
        temp_N = temp_N - 15;
        //@ assert temp_N == N - 15 * count;
    }
    
    //@ assert count == N / 15;
    result = result - 200 * count;
    //@ assert result == 800 * N - 200 * (N / 15);
    return result;
}
