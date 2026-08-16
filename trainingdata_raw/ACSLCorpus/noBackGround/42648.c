#include <stdint.h>

/*@
    requires 1 <= N && N <= 1000;
    ensures \result == N / 3;
*/
int64_t func(int64_t N)
{
    int64_t count;
    int64_t temp;

    count = 0;
    temp = N;

    /*@
        loop invariant 0 <= count;
        loop invariant count <= N / 3;
        loop invariant temp == N - 3 * count;
        loop invariant 1 <= N && N <= 1000;
        loop assigns count, temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp = temp - 3;
        count = count + 1;
    }

    //@ assert count == N / 3;
    return count;
}
