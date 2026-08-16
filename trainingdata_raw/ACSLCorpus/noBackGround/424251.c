#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result == ((((a) * 3 + (p))) / 2);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t k;
    int64_t res;
    int64_t count;
    int64_t temp_k;

    k = a * 3 + p;
    res = 0;
    count = 0;
    temp_k = k;

    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant 0 <= count <= ((k) / 2);
        loop invariant temp_k == k - 2 * count;
        loop assigns temp_k, count;
        loop variant temp_k;
    */
    while (temp_k >= 2)
    {
        //@ assert temp_k >= 2;
        temp_k -= 2;
        count += 1;
    }

    res = count;
    return res;
}
