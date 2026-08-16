#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        (n) * (m) <= 100 * 100);
    ensures \result == (((n) * (m) + 1) / 2 - 1);
    assigns \nothing;
*/
int64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t x;
    int64_t result;
    uint64_t i;
    uint64_t x_copy;

    //@ assert n * m <= 10000;
    
    x = n * m + 1;
    result = 0;
    i = 0;
    x_copy = x;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 1 <= m && m <= 100;
        loop invariant n * m <= 100 * 100;
        loop invariant x == n * m + 1;
        loop invariant 0 <= x_copy;
        loop invariant x_copy + 2 * i == x;
        loop invariant i <= x / 2;
        loop assigns x_copy, i;
        loop variant x_copy;
    */
    while (x_copy >= 2)
    {
        x_copy -= 2;
        i += 1;
    }
    
    result = (int64_t)i - 1;
    return result;
}
