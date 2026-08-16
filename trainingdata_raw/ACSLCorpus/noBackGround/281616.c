#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 2000);
    ensures \result <= b;
    ensures n * a >= b ==> \result == 0;
    ensures n * a < b ==> \result == b - n * a;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;
    uint64_t product;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 2000;
    
    // Prevent overflow using 64-bit intermediate
    product = (uint64_t)n * (uint64_t)a;
    
    //@ assert product <= 2000;
    
    if (product >= b)
    {
        //@ assert product >= b;
        result = 0;
    }
    else
    {
        //@ assert product < b;
        result = b - (uint32_t)product;
    }
    
    //@ assert result <= b;
    return result;
}
