#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==> (((x) % 100) * 21 <= (x));
*/
bool func(unsigned int x) {
    unsigned int mod_result;
    bool result;

    mod_result = x % 100;
    
    if (mod_result * 21 > x) {
        //@ assert mod_result * 21 > x;
        result = false;
    } else {
        //@ assert mod_result * 21 <= x;
        result = true;
    }
    
    return result;
}
