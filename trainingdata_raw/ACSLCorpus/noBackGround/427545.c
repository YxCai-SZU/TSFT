#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100);
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (x <= 500 * k);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert (1 <= (x) && (x) <= 100000);
    
    //@ assert (500 * (k)) <= 50000;
    
    if (x <= 500 * k) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
