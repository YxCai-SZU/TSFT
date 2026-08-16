#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100);
    ensures ((\result) == ((a) * 3 <= (b)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool res;
    
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert a * 3 <= 300;
    
    res = (a * 3 <= b);
    return res;
}
