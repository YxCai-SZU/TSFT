/*@
    predicate valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer temp_n_eq(integer n, integer count) = n - 8 * count;
    
    lemma count_non_negative:
        \forall integer n, count; valid_n(n) && count >= 0 ==> temp_n_eq(n, count) >= 0 ==> count >= 0;
*/

#include <stdint.h>

/*@
    requires valid_n(n);
    ensures \result >= 0 && \result <= 100 && \result * 8 <= n;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    uint32_t temp_n;
    int32_t count;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    //@ assert valid_n(n);
    //@ assert temp_n == n;
    //@ assert count == 0;
    
    /*@
        loop invariant 2 <= n && n <= 100;
        loop invariant temp_n >= 0;
        loop invariant count >= 0;
        loop invariant temp_n == n - 8 * count;
        loop assigns temp_n, count;
    */
    while (temp_n >= 8)
    {
        //@ assert temp_n >= 8;
        temp_n -= 8;
        count += 1;
        //@ assert temp_n == n - 8 * count;
    }
    
    result = count;
    
    //@ assert result >= 0;
    //@ assert result * 8 <= n;
    //@ assert result <= 100;
    
    return result;
}
