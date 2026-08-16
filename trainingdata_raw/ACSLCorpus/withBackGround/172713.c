#include <stdint.h>

/*@
    predicate bounds(uint32_t x, uint32_t y, uint32_t z) =
        x <= 10 && y <= 10 && z <= 10;

    logic integer product(integer x, integer y, integer z) = x * y * z;

    lemma no_overflow:
        \forall integer x, y, z;
            0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10 ==> x * y * z <= 1000;
*/

/*@
    requires bounds(x, y, z);
    ensures \result == product(x, y, z);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    //@ assert x <= 10 && y <= 10 && z <= 10;
    
    //@ assert x * y <= 100;
    //@ assert x * y * z <= 1000;
    
    uint32_t ret;
    ret = x * y * z;
    
    //@ assert ret == product(x, y, z);
    return ret;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
