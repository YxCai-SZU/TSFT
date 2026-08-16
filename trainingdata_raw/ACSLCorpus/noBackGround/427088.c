#include <stdint.h>

/*@
    requires 2 <= n <= 100;
    ensures \result == (((((n)) % 2 == 0) ? ((n)) / 2 : (((n)) - 1) / 2) * (((((n)) + 1) % 2 == 0) ? (((n)) + 1) / 2 : ((n)) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t half_n;
    uint64_t half_n_plus_one;
    uint64_t result;
    
    //@ assert 2 <= n <= 100;
    
    if (n % 2 == 0) {
        half_n = n / 2;
    } else {
        half_n = (n - 1) / 2;
    }
    //@ assert half_n == (((n) % 2 == 0) ? (n) / 2 : ((n) - 1) / 2);
    
    if ((n + 1) % 2 == 0) {
        half_n_plus_one = (n + 1) / 2;
    } else {
        half_n_plus_one = n / 2;
    }
    //@ assert half_n_plus_one == ((((n) + 1) % 2 == 0) ? ((n) + 1) / 2 : (n) / 2);
    
    //@ assert half_n <= 50;
    //@ assert half_n_plus_one <= 50;
    //@ assert half_n * half_n_plus_one <= 2500;
    
    result = half_n * half_n_plus_one;
    //@ assert result == (((((n)) % 2 == 0) ? ((n)) / 2 : (((n)) - 1) / 2) * (((((n)) + 1) % 2 == 0) ? (((n)) + 1) / 2 : ((n)) / 2));
    
    return result;
}
