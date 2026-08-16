#include <stdbool.h>

/*@
    predicate condition(integer N) = N % 100 * 21 <= N;
*/

/*@
    requires 1 <= N <= 100000;
    ensures \result == true <==> condition(N);
*/
bool func(unsigned int N)
{
    unsigned long long N_u64;
    bool result;

    N_u64 = (unsigned long long)N;

    if (N_u64 % 100 * 21 <= N_u64)
    {
        //@ assert condition(N_u64);
        result = true;
    }
    else
    {
        //@ assert !condition(N_u64);
        result = false;
    }

    return result;
}
