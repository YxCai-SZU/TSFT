#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x >= 2000 || (((x) / 100) * 100 + ((x) % 100 / 5) * 5) <= x);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int temp_expr;
    
    //@ assert (1 <= (x) <= 100000);
    
    if (x >= 2000) {
        result = true;
    } else {
        temp_expr = (x / 100) * 100 + (x % 100 / 5) * 5;
        if (temp_expr > x) {
            result = false;
        } else {
            result = true;
        }
    }
    
    //@ assert result == (x >= 2000 || (((x) / 100) * 100 + ((x) % 100 / 5) * 5) <= x);
    return result;
}
