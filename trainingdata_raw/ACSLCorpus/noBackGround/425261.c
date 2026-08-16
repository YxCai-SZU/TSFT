#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 && 1 <= (t) <= 10000 && 1 <= (s) <= 10000);
    ensures \result == 1 <==> ((s) * (t) >= (d));
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    bool will_arrive;
    
    //@ assert s <= 10000;
    //@ assert t <= 10000;
    //@ assert s * t <= 10000 * 10000;
    
    will_arrive = (s * t >= d);
    return will_arrive;
}
