#include <limits.h>
#include <stdbool.h>

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    ensures \result == true <==> a < b && b < c;
    ensures \result == false <==> !(a < b && b < c);
*/
bool func(int a, int b, int c)
{
    bool result = false;
    
    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    //@ assert c >= INT_MIN && c <= INT_MAX;
    
    if (a < b)
    {
        if (b < c)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }
    
    //@ assert result == true <==> ((a) < (b) && (b) < (c));
    
    return result;
}
