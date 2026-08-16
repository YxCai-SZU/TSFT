#include <stdbool.h>

/*@
    requires 1 <= N <= 10000;
    requires 0 <= A <= 1000;
    ensures \result == ((N % 500) <= A);
    assigns \nothing;
*/
bool func(unsigned int N, unsigned int A)
{
    unsigned int r;
    unsigned int z;
    bool result;

    r = N / 500;
    z = N - (r * 500);

    //@ assert ((r) == (N) / 500 && (z) == (N) - ((r) * 500) && (z) == (N) % 500);
    //@ assert z == N % 500;

    result = (z <= A);
    return result;
}
