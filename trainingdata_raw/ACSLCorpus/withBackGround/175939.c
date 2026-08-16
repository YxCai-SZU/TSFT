#include <stdint.h>

/*@
    predicate valid_x(integer x) = 1 <= x <= 1000000000000;
    
    logic integer compute_result(integer x) = 
        1000 * (x / 500) + 5 * ((x % 500) / 5);
*/

/*@
    requires valid_x(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t q1 = 0;
    int64_t q2 = 0;
    int64_t r1 = 0;
    
    /*@
        loop invariant 1 <= x <= 1000000000000;
        loop invariant 0 <= q1;
        loop invariant temp_x >= 0;
        loop invariant temp_x == x - 500 * q1;
        loop invariant q1 <= x / 500;
        loop assigns q1, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        q1 += 1;
        temp_x -= 500;
    }
    
    result += 1000 * q1;
    r1 = temp_x;
    
    /*@
        loop invariant 1 <= x <= 1000000000000;
        loop invariant 0 <= q2;
        loop invariant r1 >= 0;
        loop invariant r1 == temp_x - 5 * q2;
        loop invariant q2 <= temp_x / 5;
        loop assigns q2, r1;
        loop variant r1;
    */
    while (r1 >= 5)
    {
        q2 += 1;
        r1 -= 5;
    }
    
    result += 5 * q2;
    
    //@ assert result == compute_result(x);
    
    return result;
}
