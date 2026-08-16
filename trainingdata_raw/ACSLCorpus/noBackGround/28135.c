#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    ensures ((a) % 2 == 0) ==> \result == 1;
    ensures ((a) % 2 != 0) ==> \result == -1;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert 1 <= a <= 100;
    
    if (a % 2 == 0)
    {
        //@ assert ((a) % 2 == 0);
        
        if (a == 0)
        {
            //@ assert ((a) % 2 == 0);
            result = 0;
        }
        else
        {
            //@ assert ((a) % 2 == 0);
            result = 1;
        }
    }
    else
    {
        //@ assert ((a) % 2 != 0);
        result = -1;
    }
    
    return result;
}
