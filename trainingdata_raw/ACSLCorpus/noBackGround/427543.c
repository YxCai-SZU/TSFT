#include <stdbool.h>

/*@
    requires 1 <= N <= 10000;
    requires 0 <= A <= 1000;
    ensures \result == (N % 500 <= A);
*/
bool func(int N, int A)
{
    int remainder;
    remainder = N;

    /*@
        loop invariant (0 <= (remainder) <= (N) &&
        (N) % 500 == (remainder) % 500);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500)
    {
        //@ assert remainder >= 500;
        remainder = remainder - 500;
    }

    //@ assert remainder == N % 500;
    //@ assert (remainder <= A) == (N % 500 <= A);
    return remainder <= A;
}
