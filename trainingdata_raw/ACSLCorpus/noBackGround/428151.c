#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (b >= 2 * a && (b - 2 * a) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int b_local = b;
    bool res = false;

    //@ assert (1 <= (a) <= 100 && 1 <= (b_local) <= 100);

    if (b_local >= 2 * a)
    {
        b_local -= 2 * a;
        //@ assert b_local == \at(b, Pre) - 2 * a;
        
        if (b_local % 2 == 0)
        {
            res = true;
        }
        //@ assert res == (b_local % 2 == 0);
    }
    //@ assert res == (b >= 2 * a && (b - 2 * a) % 2 == 0);
    
    return res;
}
