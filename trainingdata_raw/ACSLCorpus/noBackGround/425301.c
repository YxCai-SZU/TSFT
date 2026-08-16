#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100);
    ensures ((\result) <==> ((a) + (b) == (c)) || ((a) + (c) == (b)) || ((b) + (c) == (a)));
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    bool can_distribute;
    can_distribute = (a + b == c) || (a + c == b) || (b + c == a);
    return can_distribute;
}
