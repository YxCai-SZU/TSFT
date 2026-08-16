#include <stdbool.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (1600 <= (x));
    ensures \result == 2 ==> (1200 <= (x) && (x) < 1600);
    ensures \result == 3 ==> (400 <= (x) && (x) < 1200);
*/
int func(int x)
{
    int result;

    //@ assert (400 <= (x) && (x) < 2000);
    
    if (x >= 1600)
    {
        //@ assert (1600 <= (x));
        result = 1;
    }
    else if (x >= 1200)
    {
        //@ assert (1200 <= (x) && (x) < 1600);
        result = 2;
    }
    else
    {
        //@ assert (400 <= (x) && (x) < 1200);
        result = 3;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}
