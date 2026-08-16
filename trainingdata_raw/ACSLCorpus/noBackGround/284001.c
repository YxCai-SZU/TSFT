#include <stdbool.h>

/*@
    requires 1 <= h <= 10000;
    requires 1 <= a <= 10000;
    ensures \result == true <==> h <= a;
    ensures \result == false <==> h > a;
*/
bool func(int h, int a)
{
    bool result;
    
    //@ assert 1 <= h <= 10000;
    //@ assert 1 <= a <= 10000;
    
    if (h <= a)
    {
        //@ assert ((h) <= (a));
        result = true;
    }
    else
    {
        //@ assert ((h) > (a));
        result = false;
    }
    
    return result;
}
