#include <stdbool.h>

/*@
    requires -1000 <= a <= 1000;
    requires -1000 <= b <= 1000;
    ensures \result == true <==> (((a) < 0 && (b) > 0) ||
        ((a) == 0 && (b) >= 0) ||
        ((a) > 0 && (b) == 0));
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;
    
    //@ assert -1000 <= a <= 1000;
    //@ assert -1000 <= b <= 1000;
    
    if (a < 0 && b > 0) {
        //@ assert (((a) < 0 && (b) > 0) ||         ((a) == 0 && (b) >= 0) ||         ((a) > 0 && (b) == 0));
        result = true;
    } else if (a == 0 && b >= 0) {
        //@ assert (((a) < 0 && (b) > 0) ||         ((a) == 0 && (b) >= 0) ||         ((a) > 0 && (b) == 0));
        result = true;
    } else if (a > 0 && b == 0) {
        //@ assert (((a) < 0 && (b) > 0) ||         ((a) == 0 && (b) >= 0) ||         ((a) > 0 && (b) == 0));
        result = true;
    } else {
        //@ assert !(((a) < 0 && (b) > 0) ||         ((a) == 0 && (b) >= 0) ||         ((a) > 0 && (b) == 0));
        result = false;
    }
    
    //@ assert result == true <==> (((a) < 0 && (b) > 0) ||         ((a) == 0 && (b) >= 0) ||         ((a) > 0 && (b) == 0));
    return result;
}
