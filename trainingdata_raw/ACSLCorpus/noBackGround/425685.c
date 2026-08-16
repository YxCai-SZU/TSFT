#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 1000000000000 &&
      1 <= (m) && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t nb;
    uint64_t nb4;
    uint64_t res;

    //@ assert (1 <= (n) && (n) <= 1000000000000 &&       1 <= (m) && (m) <= 1000000000000);
    
    if (n > m / 2) {
        nb = m / 2;
    } else {
        nb = n;
    }
    
    //@ assert nb == ((n) > (m) / 2 ? (m) / 2 : (n));
    
    nb4 = m - 2 * nb;
    
    //@ assert nb4 == ((m) - 2 * (nb));
    
    res = nb + nb4 / 4;
    
    //@ assert res == ((nb) + (nb4) / 4);
    //@ assert res <= n + m / 2;
    //@ assert res >= m / 4;
    
    return res;
}
