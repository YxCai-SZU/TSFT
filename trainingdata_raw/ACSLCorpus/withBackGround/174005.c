#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer square(integer n) = n * n;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n <= 100;
    //@ assert n * n <= 10000;
    
    result = n * n;
    return result;
}

int main(void)
{
    return 0;
}
