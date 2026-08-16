#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
    ensures \result == (((k) * 500) >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    // Variable declarations at scope top
    unsigned int en;
    unsigned int u;
    bool result;

    en = 500;
    
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert (1 <= (x) && (x) <= 100000);
    //@ assert ((k) * 500) <= 50000;
    //@ assert x <= 100000;
    
    u = k * en;
    
    if (u >= x) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
