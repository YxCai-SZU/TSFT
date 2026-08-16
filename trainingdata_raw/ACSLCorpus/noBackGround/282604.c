#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (k) && (k) <= 100);
    ensures \result == (((n) - 2) * ((k) - 2));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (2 <= (n) && (n) <= 100 &&         2 <= (k) && (k) <= 100);
    //@ assert n - 2 <= 98;
    //@ assert k - 2 <= 98;
    //@ assert (n - 2) * (k - 2) <= 98 * 98;

    result = (n - 2) * (k - 2);
    
    //@ assert result == (((n) - 2) * ((k) - 2));
    return result;
}

int main()
{
    // Variable declarations at scope top
    uint32_t n;
    uint32_t k;
    uint32_t result;

    n = 10;
    k = 5;
    //@ assert (2 <= (n) && (n) <= 100 &&         2 <= (k) && (k) <= 100);
    result = func(n, k);
    
    return 0;
}
