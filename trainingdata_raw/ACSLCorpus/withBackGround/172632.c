#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer division_result(integer n, integer count) = n - count * 15;
    
    logic integer final_result(integer n, integer count) = n * 800 - count * 200;
*/

/*@
    requires valid_n(n);
    ensures \result == final_result(n, n / 15);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    uint32_t count;
    uint32_t temp_n;
    uint32_t i;
    
    //@ assert valid_n(n);
    result = (int32_t)(n * 800);
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 15;
        loop invariant temp_n == division_result(n, count);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        count += 1;
        //@ assert temp_n == division_result(n, count);
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= count;
        loop invariant result == final_result(n, i);
        loop assigns result, i;
        loop variant count - i;
    */
    while (i < count)
    {
        //@ assert i < count;
        result -= 200;
        i += 1;
        //@ assert result == final_result(n, i);
    }
    
    //@ assert result == final_result(n, count);
    return result;
}
