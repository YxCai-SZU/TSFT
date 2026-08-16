#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result == 0 || \result == a - b * 2;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t result;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    
    if (a > b * 2) {
        //@ assert a - b * 2 <= a;
        result = a - b * 2;
    } else {
        //@ assert 0 <= a;
        result = 0;
    }
    
    //@ assert result <= a;
    //@ assert result == 0 || result == a - b * 2;
    
    return result;
}
