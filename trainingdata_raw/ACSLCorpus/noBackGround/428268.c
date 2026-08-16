#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> (c >= a && c <= b);
    ensures \result == false <==> !(c >= a && c <= b);
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (c >= a && c <= b)
    {
        //@ assert c >= a && c <= b;
        result = true;
    }
    else
    {
        //@ assert !(c >= a && c <= b);
        result = false;
    }
    
    //@ assert result == true <==> (c >= a && c <= b);
    return result;
}
