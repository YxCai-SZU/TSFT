#include <stdint.h>

/*@
  requires 1 <= n <= 1000000000000;
  requires 1 <= m <= 1000000000000;
  ensures \result >= 0;
  ensures \result <= n + m / 2;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t result = 0;
    uint64_t local_m = m;
    
    //@ assert ((1) != (2) && (2) != (3) && (3) != (4) && (1) != (3) && (1) != (4) && (2) != (4));
    //@ assert !((1) != (2) && (2) != (2) && (2) != (3) && (1) != (2) && (1) != (3) && (2) != (3));
    
    if (n > local_m / 2)
    {
        result = local_m / 2;
    }
    else
    {
        result = n;
        local_m = local_m - 2 * n;
        result = result + local_m / 4;
    }
    
    return result;
}
