#include <limits.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a * 2 || \result == a * 2 - 1 || \result == b * 2 - 1;
    assigns \nothing;
*/
int func(int a, int b) {
    int result;
    
    //@ assert (3 <= (a) <= 20) && (3 <= (b) <= 20);
    
    if (a == b) {
        result = a * 2;
        //@ assert result == a * 2;
    } else if (a > b) {
        result = a * 2 - 1;
        //@ assert result == a * 2 - 1;
    } else {
        result = b * 2 - 1;
        //@ assert result == b * 2 - 1;
    }
    
    return result;
}
