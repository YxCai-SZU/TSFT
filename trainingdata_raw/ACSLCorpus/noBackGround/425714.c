#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures ((\result) == 3 * (a) * (a));
    ensures (3 * (a) * (a) <= 30000 && 3 * (a) * (a) >= 3);
    assigns \nothing;
*/
int32_t func(int32_t a) {
    // Variable declarations at top
    int32_t result;

    //@ assert (1 <= (a) <= 100);
    //@ assert 3 * a <= 300;
    //@ assert (3 * (a) * (a) <= 30000 && 3 * (a) * (a) >= 3);
    
    result = 3 * a * a;
    
    //@ assert ((result) == 3 * (a) * (a));
    return result;
}
