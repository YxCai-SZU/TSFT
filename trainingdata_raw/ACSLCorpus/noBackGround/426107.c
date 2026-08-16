#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000 &&
        (d) >= 0 &&
        (t) >= 0 &&
        (s) >= 0);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations
    int product;

    //@ assert (1 <= (d) <= 10000 &&         1 <= (t) <= 10000 &&         1 <= (s) <= 10000 &&         (d) >= 0 &&         (t) >= 0 &&         (s) >= 0);
    
    //@ assert 0 <= t * s <= 10000 * 10000;
    product = t * s;
    
    //@ assert product == t * s;
    //@ assert 0 <= product <= 10000 * 10000;
    
    return d <= product;
}
