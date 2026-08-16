#include <stdbool.h>

/*@
    requires 1 <= s <= 100;
    requires 1 <= w <= 100;
    ensures \result == true <==> s > w;
    assigns \nothing;
*/
bool func(int s, int w)
{
    bool result;
    
    //@ assert s > w <==> s > w;
    
    result = s > w;
    return result;
}
