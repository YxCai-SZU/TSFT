#include <stdbool.h>

/*@
    requires (1 <= (d) && (d) <= 10000 &&
        1 <= (t) && (t) <= 10000 &&
        1 <= (s) && (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    //@ assert (1 <= (d) && (d) <= 10000 &&         1 <= (t) && (t) <= 10000 &&         1 <= (s) && (s) <= 10000);
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    unsigned int walk_per_t = s * t;
    
    if (walk_per_t >= d)
    {
        return true;
    }
    else
    {
        return false;
    }
}
