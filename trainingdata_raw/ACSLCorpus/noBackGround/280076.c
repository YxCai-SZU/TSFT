#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures ((a) < 4 ==> (\result) == 0) && (((a) == 4 || (a) == 5 || (a) == 6 || (a) == 7) ==> (\result) == 1) && ((a) > 7 ==> (\result) == 2);
*/
int32_t func(uint32_t a)
{
    int32_t result;
    //@ assert (1 <= (a) && (a) <= 10);
    
    if (a < 4)
    {
        //@ assert a < 4;
        result = 0;
    }
    else if (a < 8)
    {
        //@ assert a == 4 || a == 5 || a == 6 || a == 7;
        result = 1;
    }
    else
    {
        //@ assert a > 7;
        result = 2;
    }
    
    //@ assert ((a) < 4 ==> (result) == 0) && (((a) == 4 || (a) == 5 || (a) == 6 || (a) == 7) ==> (result) == 1) && ((a) > 7 ==> (result) == 2);
    return result;
}
