#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == 1 <==> ((((a)) == 5 && (((b)) == 5 || ((c)) == 5 || ((b)) == 7 || ((c)) == 7)) || (((b)) == 5 && (((a)) == 5 || ((c)) == 5 || ((a)) == 7 || ((c)) == 7)) || (((c)) == 5 && (((b)) == 5 || ((a)) == 5 || ((b)) == 7 || ((a)) == 7)));
*/
bool func(int a, int b, int c)
{
    bool result;
    result = false;
    
    if (a == 5)
    {
        if (b == 5 || c == 5 || b == 7 || c == 7)
        {
            result = true;
        }
    }
    else if (b == 5)
    {
        if (a == 5 || c == 5 || a == 7 || c == 7)
        {
            result = true;
        }
    }
    else if (c == 5)
    {
        if (b == 5 || a == 5 || b == 7 || a == 7)
        {
            result = true;
        }
    }
    
    //@ assert result == 1 <==> ((((a)) == 5 && (((b)) == 5 || ((c)) == 5 || ((b)) == 7 || ((c)) == 7)) || (((b)) == 5 && (((a)) == 5 || ((c)) == 5 || ((a)) == 7 || ((c)) == 7)) || (((c)) == 5 && (((b)) == 5 || ((a)) == 5 || ((b)) == 7 || ((a)) == 7)));
    
    return result;
}
