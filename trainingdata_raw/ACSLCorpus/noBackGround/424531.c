#include <stdint.h>

/*@
    requires 1 <= N <= 100 && 1 <= M <= N && M <= 5;
    ensures \result >= 100 * (N - M) + 1900 * M;
    ensures \result <= 100 * (N - M) + 1900 * M * 2;
*/
int32_t func(uint32_t N, uint32_t M)
{
    int32_t ans;
    uint32_t shift_count;
    
    //@ assert (1 <= (N) <= 100 && 1 <= (M) <= (N) && (M) <= 5);
    ans = 100 * ((int32_t)N - (int32_t)M) + 1900 * (int32_t)M;
    shift_count = M;
    
    /*@
        loop invariant 0 <= shift_count <= M;
        loop invariant ans >= 100 * (N - M) + 1900 * M;
        loop invariant ans <= 100 * (N - M) + 1900 * M * 2;
        loop invariant ans == 100 * (N - M) + 1900 * M + 100 * (M - shift_count);
        loop assigns ans, shift_count;
        loop variant shift_count;
    */
    while (shift_count > 0) {
        //@ assert shift_count > 0;
        ans += 100;
        shift_count -= 1;
        //@ assert ans == 100 * (N - M) + 1900 * M + 100 * (M - shift_count);
    }
    
    //@ assert ans == 100 * (N - M) + 1900 * M + 100 * M;
    return ans;
}
