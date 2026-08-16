#include <stdint.h>

/*@
    requires 1 <= k <= 100;
    ensures \result == ((k) * (k) * (k) + 3 * (k) * (k) + 2 * (k) + 1);
    assigns \nothing;
*/
uint64_t func(uint64_t k)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert 1 <= k <= 100;
    
    //@ assert k * k <= 10000;
    //@ assert k * k * k <= 1000000;
    //@ assert 3 * k * k <= 30000;
    //@ assert 2 * k <= 200;

    result = k * k * k + 3 * k * k + 2 * k + 1;
    
    //@ assert result == ((k) * (k) * (k) + 3 * (k) * (k) + 2 * (k) + 1);
    return result;
}

int main()
{
    return 0;
}
