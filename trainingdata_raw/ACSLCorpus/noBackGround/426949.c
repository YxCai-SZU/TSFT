#include <stdbool.h>

/*@
    requires (1 <= (x) <= 10000);
    ensures \result == true <==> ((2000 <= (x) <= 4000) || (6000 <= (x) <= 8000));
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    
    //@ assert 1 <= x <= 10000;
    
    if ((x >= 2000 && x <= 4000) || (x >= 6000 && x <= 8000)) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
