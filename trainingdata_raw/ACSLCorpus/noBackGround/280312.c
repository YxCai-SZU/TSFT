#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (c >= a && c <= b);
*/
bool func(long a, long b, long c)
{
    bool result;
    
    if (a > b)
    {
        //@ assert !(c >= a && c <= b);
        result = false;
        return result;
    }
    
    if (a <= c && c <= b)
    {
        //@ assert c >= a && c <= b;
        result = true;
        return result;
    }
    else
    {
        //@ assert !(c >= a && c <= b);
        result = false;
        return result;
    }
}
