#include <stdbool.h>

/*@
    requires (0 <= (X) <= 1);
    ensures \result == (1 - (X));
*/
int func(int X)
{
    int result;
    
    //@ assert (0 <= (X) <= 1);
    
    if (X == 1)
    {
        //@ assert (1 - (X)) == 0;
        result = 0;
    }
    else
    {
        //@ assert (1 - (X)) == 1;
        result = 1;
    }
    
    //@ assert result == (1 - (X));
    return result;
}
