#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) == 1 ? -1 :
        (n) == 2 ? 0 :
        (n) == 3 ? 1 :
        0);
    ensures -2 <= \result && \result <= 2;
    ensures \result == -2 || \result == -1 || \result == 0 || \result == 1 || \result == 2;
*/
int func(int n)
{
    int result = 0;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    if (n == 1)
    {
        //@ assert -1 >= -2 && -1 <= 2;
        result = -1;
    }
    else if (n == 2)
    {
        //@ assert 0 >= -2 && 0 <= 2;
        result = 0;
    }
    else if (n == 3)
    {
        //@ assert 1 >= -2 && 1 <= 2;
        result = 1;
    }
    
    //@ assert result == ((n) == 1 ? -1 :         (n) == 2 ? 0 :         (n) == 3 ? 1 :         0);
    //@ assert -2 <= result && result <= 2;
    //@ assert result == -2 || result == -1 || result == 0 || result == 1 || result == 2;
    
    return result;
}
