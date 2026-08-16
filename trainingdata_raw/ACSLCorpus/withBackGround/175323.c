#include <stdint.h>

/*@
    predicate N_in_range(integer N) = 3 <= N <= 100;
    
    logic integer formula(integer N) = 180 * (N - 2);
*/

/*@
    requires N_in_range(N);
    assigns \nothing;
    ensures \result == formula(N);
*/
int64_t func(int64_t N)
{
    int64_t result;
    int64_t i;
    
    result = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant result == 180 * i;
        loop invariant i > 0 ==> result == 180 * (i - 2) + 360;
        loop assigns result, i;
        loop variant N - i;
    */
    while (i < N)
    {
        //@ assert result == 180 * i;
        result += 180;
        i += 1;
    }
    
    //@ assert result == 180 * N;
    result -= 360;
    
    //@ assert result == formula(N);
    return result;
}
