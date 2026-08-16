#include <stddef.h>
#include <stdint.h>

/*@
    requires ((N) >= 1 && (N) <= 200000 &&
        \valid((p) + (0 .. (N)-1)) &&
        (\forall integer k; 0 <= k < (N) ==> (p)[k] >= 1 && (p)[k] <= (int64_t)(N)) &&
        (\forall integer k, j; 0 <= k < j < (N) ==> (p)[k] != (p)[j]));
    assigns \nothing;
    ensures \result >= 1 && \result <= (int32_t)N;
*/
int32_t func(size_t N, const int64_t *p)
{
    int32_t ans = 1;
    int64_t min_bound = p[0];
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= N;
        loop invariant ((ans) >= 1 && (ans) <= ((integer)i));
        loop invariant min_bound <= p[0];
        loop invariant \forall integer k; 0 <= k < i ==> p[k] >= 1 && p[k] <= (int64_t)N;
        loop invariant \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
        loop invariant i > 1 ==> min_bound <= p[i-1];
        loop assigns i, ans, min_bound;
        loop variant N - i;
    */
    while (i < N)
    {
        //@ assert i < N;
        if (p[i] <= min_bound)
        {
            min_bound = p[i];
            ans += 1;
        }
        //@ assert ((ans) >= 1 && (ans) <= ((integer)i + 1));
        i += 1;
    }

    //@ assert ((ans) >= 1 && (ans) <= ((integer)N));
    return ans;
}
