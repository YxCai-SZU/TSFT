#include <stdint.h>

/*@
    predicate valid_params(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;
    
    logic integer total_sum(integer a, integer p) =
        3 * a + p;
*/

/*@
    requires valid_params(a, p);
    ensures \result >= 0;
    ensures \result <= total_sum(a, p);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t sum;
    int64_t result;
    int64_t count;
    int64_t bit;
    
    //@ assert valid_params(a, p);
    sum = 3 * a + p;
    result = 0;
    count = sum;
    bit = 1;
    
    /*@
        loop invariant 0 <= count <= sum;
        loop invariant result >= 0;
        loop invariant result <= (sum - count) / 2;
        loop invariant sum == total_sum(a, p);
        loop invariant valid_params(a, p);
        loop assigns count, result;
        loop variant count;
    */
    while (count >= 2)
    {
        count -= 2;
        result += bit;
    }
    
    //@ assert result >= 0;
    //@ assert result <= total_sum(a, p);
    return result;
}

int main(void)
{
    return 0;
}
