#include <stdbool.h>

/*@
    requires 0 <= h1 < 0x1000;
    requires 0 <= h2 < 0x1000;
    ensures \result == (h1 == h2);
*/
bool example_hmap(unsigned long long h1, unsigned long long h2)
{
    //@ assert (0 <= (h1) < 0x1000);
    //@ assert (0 <= (h2) < 0x1000);
    
    bool result;
    result = (h1 == h2);
    
    //@ assert result == (h1 == h2);
    return result;
}
