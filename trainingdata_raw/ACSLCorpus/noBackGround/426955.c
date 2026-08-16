#include <stdint.h>

/*@
    requires ((a) > 0 && (a) * 5 <= 2147483647);
    ensures \result == ((a) * 5);
    assigns \nothing;
*/
int32_t perimeter_pentagon(int32_t a)
{
    // Variable declarations at top of scope
    int32_t ret;
    
    //@ assert a > 0;
    //@ assert a * 5 <= 2147483647;
    
    ret = a * 5;
    
    //@ assert ret == ((a) * 5);
    
    return ret;
}
