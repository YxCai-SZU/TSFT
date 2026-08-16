/*@
    predicate bounds(integer a, integer b, integer c, integer d, integer e, integer f, integer sum, integer i, integer k) =
        0 <= i <= k &&
        a <= i && b <= i && c <= i && d <= i && e <= i && f <= i &&
        sum <= i * 100 &&
        1 <= k <= 99999 &&
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && f >= 0 &&
        sum >= 0;

    lemma sum_nonnegative: \forall integer a, b, c, d, e, f, sum, i, k;
        bounds(a, b, c, d, e, f, sum, i, k) ==> sum >= 0;
*/

#include <stdint.h>

/*@ requires 1 <= k <= 99999;
    ensures \result >= 0;
    assigns \nothing;
 */
int32_t func(uint32_t k)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    uint32_t d = 0;
    uint32_t e = 0;
    uint32_t f = 0;
    uint32_t sum = 0;
    uint32_t i = 0;
    
    /*@ loop invariant bounds(a, b, c, d, e, f, sum, i, k);
        loop invariant i <= k;
        loop assigns a, b, c, d, e, f, sum, i;
        loop variant k - i;
     */
    while (i < k) {
        f = i / 5;
        e = i / 10 + f;
        d = i / 50 + e;
        c = i / 100 + d;
        b = i / 500 + c;
        a = i / 1000 + b;
        sum = a;
        i += 1;
        
        //@ assert sum >= 0;
    }
    
    return (int32_t)sum;
}

/*@ assigns \nothing;
 */
int main() {
    return 0;
}
