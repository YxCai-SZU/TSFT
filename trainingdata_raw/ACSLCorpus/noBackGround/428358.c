#include <stdbool.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == ((N) / 3);
    assigns \nothing;
*/
int func(int N)
{
    int result;
    int temp_N;
    int count;
    
    result = 0;
    temp_N = N;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count <= ((N) / 3);
        loop invariant temp_N == N - 3 * count;
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 3)
    {
        //@ assert temp_N >= 3;
        temp_N = temp_N - 3;
        count = count + 1;
    }
    
    result = count;
    return result;
}
