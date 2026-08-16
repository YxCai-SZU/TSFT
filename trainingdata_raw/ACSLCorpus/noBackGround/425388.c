#include <stdint.h>

/*@ requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
*/
int32_t func(uint32_t a, uint32_t p)
{
    uint32_t k;
    uint32_t result;
    uint32_t count;
    uint32_t temp_k;

    k = a * 3 + p;
    result = 0;
    count = 0;
    temp_k = k;

    /*@
        loop invariant temp_k + 2 * count == k;
        loop invariant count <= k / 2;
        loop invariant temp_k <= k;
        loop assigns temp_k, count;
    */
    while (temp_k >= 2)
    {
        temp_k -= 2;
        count += 1;
    }
    result = count;

    //@ assert result == (((a) * 3 + (p)) / 2);
    return (int32_t)result;
}
