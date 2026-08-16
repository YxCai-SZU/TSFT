#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n <= 10000;
    logic integer target_value(integer n) = (n + 999) / 1000;
 */

/*@
    requires is_valid_n(n);
    ensures \result == target_value(n);
    assigns \nothing;
 */
size_t func(size_t n)
{
    // Variable declarations at top of scope
    size_t count = 0;
    size_t temp_n = n + 999;
    
    //@ assert 1 <= n <= 10000;
    //@ assert n + 999 <= 10000 + 999;
    
    /*@
        loop invariant 0 <= count;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n + 999 - 1000 * count;
        loop invariant count <= target_value(n);
        loop assigns count, temp_n;
        loop variant temp_n;
     */
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        count += 1;
    }
    
    //@ assert count == target_value(n);
    return count;
}
