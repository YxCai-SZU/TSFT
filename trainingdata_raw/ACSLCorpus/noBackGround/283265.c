#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result == ((((a)) * 3 + ((p))) / 2);
    assigns \nothing;
 */
uint64_t func(uint64_t a, uint64_t p)
{
    uint64_t k;
    uint64_t ans;
    uint64_t temp_k;
    uint64_t count;

    k = a * 3 + p;
    ans = 0;
    temp_k = k;
    count = 0;

    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant 0 <= count <= k / 2;
        loop invariant temp_k + 2 * count == k;
        loop assigns temp_k, count;
     */
    while (temp_k >= 2)
    {
        //@ assert temp_k >= 2;
        temp_k -= 2;
        count += 1;
    }
    ans = count;

    //@ assert ans == ((((a)) * 3 + ((p))) / 2);
    return ans;
}
