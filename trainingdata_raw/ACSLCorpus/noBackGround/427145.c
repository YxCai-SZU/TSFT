#include <stdbool.h>

/*@
    requires ((a) >= 0 && (a) < 24 && (b) >= 0 && (b) < 60) && ((c) >= 0 && (c) < 24 && (d) >= 0 && (d) < 60);
    ensures \result == ((((c) < (a) || ((c) == (a) && (d) < (b))) ? 1 : 0) == 1);
*/
bool func(int a, int b, int c, int d)
{
    //@ assert ((a) >= 0 && (a) < 24 && (b) >= 0 && (b) < 60);
    //@ assert ((c) >= 0 && (c) < 24 && (d) >= 0 && (d) < 60);
    
    bool result;
    
    if (c < a)
    {
        //@ assert (((c) < (a) || ((c) == (a) && (d) < (b))) ? 1 : 0) == 1;
        result = true;
    }
    else if (c == a)
    {
        result = (d < b);
    }
    else
    {
        result = false;
    }
    
    //@ assert result == ((((c) < (a) || ((c) == (a) && (d) < (b))) ? 1 : 0) == 1);
    return result;
}
