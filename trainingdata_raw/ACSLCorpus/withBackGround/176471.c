#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == b + d || \result == a + c || \result == a + d || \result == b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    int64_t ac = a + c;
    int64_t bd = b + d;
    int64_t ad = a + d;
    int64_t bc = b + c;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (ac > bd)
    {
        if (ac > ad)
        {
            if (ac > bc)
            {
                x = ac;
            }
            else
            {
                x = bc;
            }
        }
        else
        {
            if (ad > bc)
            {
                x = ad;
            }
            else
            {
                x = bc;
            }
        }
    }
    else
    {
        if (bd > ad)
        {
            if (bd > bc)
            {
                x = bd;
            }
            else
            {
                x = bc;
            }
        }
        else
        {
            if (ad > bc)
            {
                x = ad;
            }
            else
            {
                x = bc;
            }
        }
    }

    //@ assert x == b + d || x == a + c || x == a + d || x == b + c;
    return x;
}
