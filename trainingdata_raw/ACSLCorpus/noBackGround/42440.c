#include <stdbool.h>

/*@
    requires 0 <= x <= 50;
    requires 0 <= y <= 60;
    requires 0 <= z <= 100;
    ensures \result == (x * y <= 2000 && (x * y) * z <= 200000);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int max_val;
    unsigned int min_val;
    bool result;
    
    //@ assert x * y <= 3000;
    
    //@ assert (x * y) * z <= 300000;
    
    if (x * y > 2000)
    {
        max_val = x * y;
    }
    else
    {
        max_val = 2000;
    }
    
    if (x * y < 2000)
    {
        min_val = x * y;
    }
    else
    {
        min_val = 2000;
    }
    
    //@ assert max_val == x * y || max_val == 2000;
    
    //@ assert min_val == x * y || min_val == 2000;
    
    result = (x * y <= 2000) && ((x * y) * z <= 200000);
    return result;
}
