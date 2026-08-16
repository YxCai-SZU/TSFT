#include <stdbool.h>

/*@
    requires (-2000 <= (d) <= 2000);
    ensures \result == (d >= 0);
    assigns \nothing;
*/
bool check_collision(int d) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert d >= 0 <==> d >= 0;
    
    result = (d >= 0);
    return result;
}
