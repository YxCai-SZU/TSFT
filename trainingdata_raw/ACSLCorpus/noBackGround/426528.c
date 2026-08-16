#include <stdbool.h>

/*@
    requires (0 <= (x) <= 10000 && 0 <= (y) <= 10000 && 0 <= (z) <= 10000);
    ensures \result == (((x) * (y)) >= z);
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert 0 <= x <= 10000 && 0 <= y <= 10000 && 0 <= z <= 10000;
    
    //@ assert ((x) * (y)) <= 100000000;
    //@ assert ((x) * (y)) >= 0;
    
    unsigned int product = x * y;
    //@ assert product == ((x) * (y));
    
    bool result = product >= z;
    //@ assert result == (((x) * (y)) >= z);
    
    return result;
}
