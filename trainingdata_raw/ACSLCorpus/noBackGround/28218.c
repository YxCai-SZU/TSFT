#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == (((k) * 500) >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    unsigned int total;
    bool result;

    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    
    //@ assert ((k) * 500) <= 50000;
    total = k * 500;
    
    if (total >= x) {
        //@ assert ((k) * 500) >= x;
        result = true;
    } else {
        //@ assert !(((k) * 500) >= x);
        result = false;
    }
    
    return result;
}
