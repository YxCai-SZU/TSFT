#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == (n == 7 || n == 5 || n == 3);
    assigns \nothing;
*/
bool func(int n)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (n) && (n) <= 9);
    
    switch (n) {
        case 7:
        case 5:
        case 3:
            result = true;
            break;
        default:
            result = false;
            break;
    }
    
    return result;
}
