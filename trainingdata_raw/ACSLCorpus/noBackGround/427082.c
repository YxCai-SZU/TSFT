#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (x) && (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    unsigned int en;
    bool result;

    en = 500;
    
    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    
    result = (k * en >= x);
    return result;
}
