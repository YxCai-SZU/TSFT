#include <stdint.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result <= a + b + c;
  ensures ((\result) == (a) + (b) || (\result) == (b) + (c) || (\result) == (a) + (c));
  assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ab;
    uint32_t bc;
    uint32_t ca;
    uint32_t min_ab_bc;
    uint32_t min_bc_ca;
    uint32_t min_ab_ca;
    uint32_t max_ab_bc;
    uint32_t max_bc_ca;
    uint32_t max_ab_ca;
    uint32_t result;

    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;

    ab = a + b;
    bc = b + c;
    ca = c + a;

    min_ab_bc = (ab < bc) ? ab : bc;
    min_bc_ca = (bc < ca) ? bc : ca;
    min_ab_ca = (ab < ca) ? ab : ca;

    max_ab_bc = (ab > bc) ? ab : bc;
    max_bc_ca = (bc > ca) ? bc : ca;
    max_ab_ca = (ab > ca) ? ab : ca;

    if (min_ab_bc < min_bc_ca)
    {
        if (min_ab_bc < min_ab_ca)
        {
            result = min_ab_bc;
        }
        else
        {
            result = min_ab_ca;
        }
    }
    else
    {
        if (min_bc_ca < min_ab_ca)
        {
            result = min_bc_ca;
        }
        else
        {
            result = min_ab_ca;
        }
    }

    //@ assert result <= max_ab_bc;
    //@ assert result <= max_bc_ca;
    //@ assert result <= max_ab_ca;

    return result;
}
