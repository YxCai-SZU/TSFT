#include <stdbool.h>

/*@
    requires (1 <= (x) <= 9);
    ensures \result == true <==> ((x) == 7 || (x) == 5 || (x) == 3);
    assigns \nothing;
*/
bool func(long x) {
    bool result;
    
    //@ assert (1 <= (x) <= 9);
    
    result = (x == 7 || x == 5 || x == 3);
    
    //@ assert result == true <==> ((x) == 7 || (x) == 5 || (x) == 3);
    
    return result;
}
