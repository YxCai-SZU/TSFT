#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    bool result;
    unsigned int product;
    
    //@ assert (1 <= (a) * (b) <= 10000 * 10000);
    product = a * b;
    
    if (product % 2 == 0) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
