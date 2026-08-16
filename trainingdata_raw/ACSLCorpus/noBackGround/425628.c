#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    // Variable declarations at top of scope
    int value;
    bool result;
    
    //@ assert (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    
    value = 500 * k;
    
    //@ assert value == (500 * (k));
    
    if (value >= x) {
        //@ assert value >= x;
        result = true;
    } else {
        //@ assert !(value >= x);
        result = false;
    }
    
    //@ assert result == (value >= x);
    return result;
}
