#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer total_sum(integer a, integer b, integer h) = (a + b) * h;

    lemma sum_bound: \forall integer a, b, h;
        valid_params(a, b, h) ==> total_sum(a, b, h) <= 20000;

    lemma division_identity: \forall integer a, b, h;
        valid_params(a, b, h) ==> total_sum(a, b, h) / 2 == (a + b) * h / 2;
*/

/*@
    requires valid_params(a, b, h);
    ensures \result == (a + b) * h / 2;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    // Variable declarations at top
    uint64_t sum;
    uint64_t ans;
    uint64_t i;
    uint64_t temp_sum;

    //@ assert 1 <= a + b <= 200;
    
    //@ assert total_sum(a, b, h) <= 20000;
    sum = (a + b) * h;
    
    ans = 0;
    i = 0;
    temp_sum = sum;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant sum == total_sum(a, b, h);
        loop invariant temp_sum >= 0;
        loop invariant sum == temp_sum + 2 * i;
        loop invariant i >= 0;
        loop invariant i <= sum / 2;
        loop assigns temp_sum, i;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        i += 1;
    }
    
    ans = i;
    //@ assert sum / 2 == (a + b) * h / 2;
    return ans;
}
