#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9);
    requires (1 <= (g) <= 9);
    requires (1 <= (b) <= 9);
    ensures \result == ( (r * 100 + g * 10 + b) % 4 == 0 );
    assigns \nothing;
*/
bool func(unsigned long r, unsigned long g, unsigned long b)
{
    // Variable declarations at top of scope
    unsigned long rgb_val;
    bool result;

    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);
    
    rgb_val = r * 100 + g * 10 + b;
    result = (rgb_val % 4 == 0);
    
    return result;
}
