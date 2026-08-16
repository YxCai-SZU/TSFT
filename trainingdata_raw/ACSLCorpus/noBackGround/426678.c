#include <stdbool.h>

/*@
    requires (1 <= (n) <= 9);
    ensures \result == (n == 3 || n == 5 || n == 7);
    assigns \nothing;
*/
bool func(int n) {
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n <= 9;
    
    if (n == 3 || n == 5 || n == 7) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
