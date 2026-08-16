#include <stdbool.h>

/*@ predicate is_hot(integer x) = 30 <= x; */

/*@
    requires -40 <= x <= 40;
    ensures \result == true <==> 30 <= x;
    ensures \result == false <==> x < 30;
*/
bool func(int x)
{
    bool result;
    
    //@ assert -40 <= x && x <= 40;
    
    if (30 <= x) {
        result = true;
        //@ assert is_hot(x);
    } else {
        //@ assert x < 30;
        result = false;
    }
    
    //@ assert result == true <==> 30 <= x;
    return result;
}
