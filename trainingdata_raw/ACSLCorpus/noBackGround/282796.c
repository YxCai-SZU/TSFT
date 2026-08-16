#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == true <==> a % 2 == 1;
    assigns \nothing;
*/
bool func(int a)
{
    bool is_odd = false;
    
    //@ assert a >= 1 && a <= 10;
    
    if (a % 2 == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == true <==> a % 2 == 1;
    
    return is_odd;
}
