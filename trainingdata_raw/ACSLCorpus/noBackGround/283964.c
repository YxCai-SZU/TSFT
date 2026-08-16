#include <stdbool.h>

/*@
    requires (-40 <= (X) <= 40);
    ensures \result == (X >= 30);
    assigns \nothing;
*/
bool func(int X)
{
    bool ans;
    //@ assert (-40 <= (X) <= 40);
    
    if (X < 30) {
        ans = false;
    } else {
        ans = true;
    }
    
    //@ assert ans == (X >= 30);
    return ans;
}
