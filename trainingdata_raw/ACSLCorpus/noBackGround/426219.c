#include <stdbool.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures \result == 8 || \result == 7 || \result == 5 || \result == 3;
    assigns \nothing;
*/
int func(int x)
{
    int result;
    result = 0;
    
    if (x >= 1500) {
        result = 8;
    } else if (x >= 1000) {
        result = 7;
    } else if (x >= 600) {
        result = 5;
    } else {
        result = 3;
    }
    
    //@ assert result == 8 || result == 7 || result == 5 || result == 3;
    return result;
}
