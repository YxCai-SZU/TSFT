#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> a - b < d - c;
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    
    if (a - b < d - c)
    {
        //@ assert a - b < d - c;
        result = true;
    }
    else
    {
        //@ assert !(a - b < d - c);
        result = false;
    }
    
    //@ assert result == true <==> a - b < d - c;
    return result;
}
