#include <stdbool.h>
#include <stdint.h>

/*@
requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
    (k) >= 1 && (k) <= (a) + (b) + (c) &&
    (a) + (b) + (c) <= 2000000000);
ensures \result == k || \result == a;
*/
uint32_t find_result(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 &&     (k) >= 1 && (k) <= (a) + (b) + (c) &&     (a) + (b) + (c) <= 2000000000);
    uint32_t min_a_k;
    if (a < k) {
        min_a_k = a;
        //@ assert min_a_k == a;
    } else {
        min_a_k = k;
        //@ assert min_a_k == k;
    }
    //@ assert min_a_k == k || min_a_k == a;
    uint32_t result = min_a_k;
    //@ assert result == k || result == a;
    return result;
}

/*@ ensures \true; */
void example8(void)
{
    uint32_t v[2];
    uint32_t *s;
    uint32_t idx0;
    uint32_t idx1;
    
    v[0] = 11;
    v[1] = 21;
    s = v;
    //@ assert ((2) >= 0 && \valid((s) + (0 .. (2)-1)));
    idx0 = s[0];
    //@ assert idx0 == 11;
    idx1 = s[1];
    //@ assert idx1 == 21;
}
