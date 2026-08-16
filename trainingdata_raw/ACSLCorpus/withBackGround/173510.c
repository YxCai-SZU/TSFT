#include <stdbool.h>

/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100;
    
    logic integer manual_div_15(integer n, integer count) = n - 15 * count;
    
    lemma division_property:
        \forall integer n, integer count;
        valid_range(n) && 0 <= count && manual_div_15(n, count) >= 0 ==>
        manual_div_15(n, count) == n - 15 * count;
*/

/*@
    requires valid_range(n);
    ensures \result == n * 800 - (n / 15) * 200;
*/
long func(long n)
{
    long result;
    long count;
    long temp_n;
    bool is_negative;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    is_negative = false;
    
    if (temp_n < 0)
    {
        is_negative = true;
        temp_n = -temp_n;
    }
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant count >= 0;
        loop invariant temp_n == n - 15 * count;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        count = count + 1;
        temp_n = temp_n - 15;
    }
    
    if (is_negative)
    {
        count = -count;
    }
    
    result = result - count * 200;
    
    //@ assert result == n * 800 - (n / 15) * 200;
    
    return result;
}
