#include <stdint.h>

/*@
    requires (0 <= (n) <= 100);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Declare all variables at the top
    uint64_t result;

    //@ assert n <= 100;
    
    //@ assert n * n <= 100 * 100;
    
    //@ assert n * n * n <= 100 * 100 * 100;

    result = n * n * n;
    return result;
}

int main()
{
    return 0;
}
