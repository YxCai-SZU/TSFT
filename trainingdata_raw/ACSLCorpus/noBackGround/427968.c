#include <stdbool.h>

/*@
    requires (1 <= (s) <= 100) && (1 <= (w) <= 100);
    ensures ((\result) == ((s) <= (w)));
    assigns \nothing;
*/
bool func(int s, int w)
{
    //@ assert 1 <= s && s <= 100 && 1 <= w && w <= 100;
    
    if (s <= w) {
        return true;
    } else {
        return false;
    }
}
