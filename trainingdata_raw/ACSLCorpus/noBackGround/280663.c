#include <stddef.h>
#include <stdint.h>

/*@
    requires 2 <= N <= 100;
    requires \valid_read(B + (0 .. (N-2)));
    requires (\forall integer i; 0 <= i < (N-1) ==> 0 <= (B)[i] <= 100000);
    assigns \nothing;
    ensures \result >= 0;
*/
int32_t func(size_t N, const int32_t B[])
{
    int32_t ans;
    size_t i;
    int32_t b_i0;
    int32_t b_i1;

    ans = B[0] + B[N - 2];
    i = 0;

    /*@
        loop invariant 0 <= i <= N-2;
        loop invariant ans >= 0;
        loop invariant ans <= (100000 * ((i) + 2));
        loop assigns ans, i, b_i0, b_i1;
        loop variant N-2 - i;
    */
    while (i < N - 2)
    {
        b_i0 = B[i];
        b_i1 = B[i + 1];
        //@ assert 0 <= b_i0 <= 100000 && 0 <= b_i1 <= 100000;

        if (b_i0 < b_i1)
        {
            ans += b_i0;
        }
        else
        {
            ans += b_i1;
        }
        //@ assert ans >= 0;
        i += 1;
    }
    return ans;
}
