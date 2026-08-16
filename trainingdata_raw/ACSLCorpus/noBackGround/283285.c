#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 &&
        1 <= (X) <= 10000 &&
        \valid((L)+(0..(N)-1)) &&
        \forall integer k; 0 <= k < (N) ==> 1 <= (L)[k] <= 100);
    ensures \result <= N;
    assigns \nothing;
*/
size_t func(size_t N, uint64_t X, const uint64_t L[])
{
    uint64_t d = 0;
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= N;
        loop invariant d <= X;
        loop invariant count <= i;
        loop invariant (1 <= (N) <= 100 &&
        1 <= (X) <= 10000 &&
        \valid((L)+(0..(N)-1)) &&
        \forall integer k; 0 <= k < (N) ==> 1 <= (L)[k] <= 100);
        loop assigns d, count, i;
        loop variant N - i;
    */
    while (i < N)
    {
        uint64_t old_d = d;
        d += L[i];

        //@ assert d == old_d + L[i];

        if (d <= X)
        {
            count += 1;
        }
        else
        {
            break;
        }

        i += 1;
    }

    //@ assert count <= N;
    return count;
}

int main()
{
    return 0;
}
